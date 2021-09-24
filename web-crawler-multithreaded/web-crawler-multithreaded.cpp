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

public:
    queue<string> q;
    mutex m;
    condition_variable cv;
    unordered_set<string> hs;
    vector<string> ans;
    
    void work(HtmlParser parser, string startUrl) {
        
        while(1) {
            
            unique_lock<mutex> lock(m);
            auto ret = cv.wait_for(lock, 25ms, [&](){
                return !q.empty();
            });
            
            if(!ret) {
                return;
            }
            
            string top=q.front();
            ans.push_back(top);
            
            
            q.pop();
            
            lock.unlock();
        
            vector<string> urls = parser.getUrls(top);
            
            lock.lock();
            
            for(auto& s:urls){
                
                if(parseHostName(s) == parseHostName(startUrl) 
                    && hs.find(s)==hs.end()) {
                    
                    hs.insert(s);
                    q.push(s);
                }
            }
            lock.unlock();
        }
    }
    
    string parseHostName(string s) {
        
        s.erase(s.begin(),s.begin()+7);
        auto it = find_if(s.begin(),s.end(),[](auto c){
            return c==':' || c=='/';
        });
        return string(s.begin(),it);
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        int k=2;
        thread threads[k];
        
        hs.insert(startUrl);
        q.push(startUrl);
        
        for(int i=0;i<k;i++) {
            threads[i] = thread([this, startUrl, htmlParser](){
                work(htmlParser, startUrl);
            });
        }
        for(int i=0;i<k;i++){
            threads[i].join();
        }
        return ans;
    }
};