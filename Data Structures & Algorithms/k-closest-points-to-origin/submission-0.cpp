class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // what we can do is store the points in a pair of dist, coordinates
        // we first need to store a min heap 
        // if we want k amount
        // we can pop the min heap k-1 times and then get the top of the second
        // another optimization is making a max heap of k size
        // the idea is that the kth closest points to origin would be the kth largest point away from the origin and that would be the top of our max heap


        priority_queue<pair<int, vector<int>>> pq;


        for(auto point : points){
            int x = point[0];
            int y = point[1];


            int d = x*x + y*y;

           
            if(pq.size() == k){
                int dist = pq.top().first;
                if(d < dist){
                    pq.pop();
                    pq.push({d, {x,y}});
                }
            }else{
                pq.push({d, {x,y}});
            }
        }
        vector<vector<int>> sol;
        while(!pq.empty()){
            vector<int> point = pq.top().second;
            sol.push_back(point);
            pq.pop();
        }


        return sol;
    }
};
