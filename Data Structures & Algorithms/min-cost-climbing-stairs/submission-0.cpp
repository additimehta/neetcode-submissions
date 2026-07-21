class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // T represents the minimum cost to climb the staircase
        vector<int> T(n+ 1);

        T[0] = 0;
        T[1] = 0;

        for(int i = 2; i <= n; i++){
            T[i] = min(cost[i - 1] + T[i-1], cost[i - 2] + T[i-2] );
        }

        return T[n];

    
        
    }
};
