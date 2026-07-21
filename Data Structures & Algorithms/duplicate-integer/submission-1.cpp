#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map; 

        for (int num : nums) {
            if (map[num]) return true; 
            map[num] = true;          
        }

        return false;
    }
};
