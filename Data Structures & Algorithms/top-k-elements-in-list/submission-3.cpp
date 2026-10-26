class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;


        for(int num : nums){
            mp[num]++;
        }

// k = 2
        // 1 -> 1
        // 2 -> 2
        // 3 -> 3



        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        for(auto &[key, val] : mp){
            pq.push({val, key});

            if(pq.size() > k){
                pq.pop();
            }
        }

        // i have a size k heap, that has my top k frequent elements

        vector<int> sol;
        for(int i = 0; i < k; i++){
            sol.push_back(pq.top().second);
            pq.pop();
        }

        return sol;


        // time is O(nlogk)
        // space : O(n + k) 


    }
};
