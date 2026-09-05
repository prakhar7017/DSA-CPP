class Twitter {
private:
    struct Tweet {
        int time;
        int id;
    };
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq; // {timestamp,userid,index}

        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].time, userId, idx});
        }
        for (int followee : following[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({tweets[followee][idx].time, followee, idx});
            }
        }
        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [time, userId, idx] = pq.top();
            pq.pop();
            feed.push_back(tweets[userId][idx].id);

            if (idx > 0) {
                int nextIdx = idx - 1;
                pq.push({tweets[userId][nextIdx].time, userId, nextIdx});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */