class TweetCounts {
public:
    unordered_map<string,map<int,int>> m;
    
    unordered_map<string,int> steps = { 
        { "minute", 60 },
        { "hour", 60*60 },
        { "day", 60*60*24 }
    };
    
    void recordTweet(const string& tweetName, int time) {
        m[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(const string& freq, const string& tweetName, int startTime, int endTime) {
        int step = steps[freq];
        
        vector<int> result(1+(endTime - startTime)/step);
        
        for (auto it = m[tweetName].lower_bound(startTime); it != m[tweetName].upper_bound(endTime); ++it) {
            result[(it->first-startTime)/step] += it->second;
        }
        
        return result;
    }
};
/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
