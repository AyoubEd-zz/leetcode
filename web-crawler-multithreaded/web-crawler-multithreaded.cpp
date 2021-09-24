/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
#define THREAD_NUM 10
class Solution {
private:
    int thread_num;
    string hostname;
    queue<string> q;
    unordered_set<string> seen;
    int working = 0;
    bool done;
    mutex m;
    condition_variable cv;
    
    string extractHostName(string& url){
        int start = url.find('/') + 2;
        int end =  url.find('/', start);
        if(end == string::npos) 
            return url.substr(start);
        return url.substr(start, end - start);
    }
    vector<thread> workers;
    
    // this a worker thread that will be doing tasks.
    void startWorker(HtmlParser* parser){
        while(true){
            unique_lock<mutex> ul(m);
            // wait until there are some tasks OR
            // we are done executing
            cv.wait(ul, [&](){
                return q.size() > 0 || done;
            });
            // if done, return.
            if(done)
                return;
            // indicate that this thread is in progress
            working++;
            string item = q.front(); q.pop();
            ul.unlock();
            // since getUrls can take a lot of time, release the lock.
            auto accessible = parser->getUrls(item);
            
            // acquire the lock and add tasks.
            ul.lock();
            for(auto& url : accessible){
                // if it has been seen already or the host name doesn't match, ignore it.
                if(seen.count(url) || extractHostName(url) != hostname)
                    continue;
                seen.insert(url);
                q.push(url);
            }
            working--;
            
            // IF 
            //   1) no thread is processing
            //   2) no tasks are available even after executing this task
            // THEN we are done.
            if(working == 0 && q.empty()){
                done = true;
            }
            // notify all the threads either about finishing or about availability of tasks.
            cv.notify_all();
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        // get the hostname for this url.
        // mark it as seen.
        hostname = extractHostName(startUrl);
        seen.insert(startUrl);
        done = false;
        // get number of supported threads
        thread_num = thread::hardware_concurrency();
        // push the first task to do.
        q.push(startUrl);
        
        // start bunch of worker threads.
        for(int i = 0; i < thread_num; i++){
            workers.emplace_back(&Solution::startWorker, this, &htmlParser);
        }
        
        // join those threads so that crawl is a blocking call 
        for(auto &t : workers){
            t.join();
        }
        // return every unique processed string
        return vector<string>(seen.begin(), seen.end());
    }
};