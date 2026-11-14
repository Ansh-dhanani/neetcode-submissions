class Twitter {
private:
    int timestamp;
    //              userid,[{timestamp,postid}]
    unordered_map<int, vector<pair<int, int>>> tweets;
    //          userid, [followers]
    unordered_map<int, unordered_set<int>> following;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed;
        following[userId].insert(userId);
        for (int followeeId : following[userId]) {
            const auto& userTweets = tweets[followeeId];
            int start = max(0, (int)userTweets.size() - 10);
            for (int i = start; i < userTweets.size(); ++i) {
                feed.push_back(userTweets[i]);
            }
        }
        sort(feed.rbegin(), feed.rend());
        vector<int> res;
        for (int i = 0; i < min(10, (int)feed.size()); ++i) {
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};