class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        //T(n) represents the number of ways you can climb the nth stair
        vector<int> T(n + 1);

        // base case if you have n = 0, no stairs, or 1 stair
        T[0] = 0;
        T[1] = 1;
        T[2] = 2;
    

        for(int i = 3; i <= n; i++){
            // we can either climb one step or two steps
            // think backward, either the person took 1 step down or 2 steps down
            T[i] = T[i-1] + T[i-2];
        }

        return T[n];

        
    }
};