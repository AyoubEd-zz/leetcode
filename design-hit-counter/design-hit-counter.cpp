struct Hit{
        int timestamp;
        int count;
};

class HitCounter{
        private:
                vector<Hit> ring;
                int window = 300;
        public:
                HitCounter() {
                        ring.resize(window);
                }

                void hit(int timestamp) {
                        int pos = timestamp % window;
                        int count = 0;
                        if(ring[pos].timestamp == timestamp)
                                count = ring[pos].count;

                        ring[pos] = {timestamp, count+1};
                }

                int getHits(int timestamp) {
                        int count = 0;
                        for(const auto& a: ring) {
                                if(a.timestamp > timestamp - window)
                                        count += a.count;
                        }
                        return count;
                }
};
