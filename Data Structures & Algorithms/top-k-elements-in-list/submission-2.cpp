class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 1 --> 1
        // 2 --> 2
        // 3 --> 3

        vector<int> result;

        while(k > 0) {

            int max = 0;
            int maxFreq = 0;
            for(auto &pair : map){
                if(pair.second > maxFreq) {
                    max = pair.first;
                    maxFreq = pair.second;
                }
            }

            result.push_back(max);
            map[max] = 0;
            k--;
        }

        return result;
        
    }
};
