class Twitter {

private:
    int time = 0;
    // duplicate followers;
    unordered_map<int, vector<int>> follows;// ith user follows these people
    unordered_map<int, vector<pair<int, int>>> tweets;;// ith user posts these ids;
    // userId posts (timestamp, tweetId)

public:
    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        // keep a max heap by time
        // only store tweets that the user follows or
        //  posts of the user itself
        vector<int> news;
        priority_queue<pair<int, int>> pq; // should store(timetamp, tweetid);
        vector<pair<int, int>> &usersTweets = tweets[userId];
        vector<int> &usersFollowers = follows[userId];

        for(auto& tweet : usersTweets){
            pq.push(tweet);
        }

        for(auto&  follower : usersFollowers){
            for(auto& tweet : tweets[follower]){
                pq.push(tweet);
            }
        }

        int count = 0;

        while(!pq.empty() && count < 10){
            pair<int,int> tweet = pq.top();
            int tweetId  = tweet.second;
            news.push_back(tweetId);
            pq.pop();
            count++;
        }

        return news;

    }
    
    void follow(int followerId, int followeeId) {
        vector<int> &followerList = follows[followerId];
        bool duplicate = false;

        for(auto& follower : followerList){
            if(follower == followeeId){
                duplicate = true;
            }
        }

        if(!duplicate){
            follows[followerId].push_back(followeeId);
        }
    

    }
    
    void unfollow(int followerId, int followeeId) {
        // remove by ref
        auto & following = follows[followerId];

        following.erase(

            remove(following.begin(), following.end(), followeeId),
            following.end()
        );

    }
};
