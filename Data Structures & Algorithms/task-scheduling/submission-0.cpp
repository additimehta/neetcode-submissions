class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // A-Z in char are all incrememenlty by 1
        // n cool down 
        // u must wait n cycles to repeat the same task
        
        // brute force is try all the options and see which minimzies?
        // 26 tasks
        // store in hash map
        // the idea is to minmize the number of times we delay we should start with a task that has the highest frequency and kep going down
        // then 
        // A : 3
        // B : 1
        // C:  1
        // try to ensure that u dont process that task like A until after n secs
        // we can try storing the freq on a max heap how can we ensure to not repeat the same task within cooldown
        // for the reinsert just make sure u only reinsert the value once the cool down period has passed
        //  


       // x -> x -> n -> x -> y
        // 1 + 1 + n + 1 + 1  = 5

        // first store all chars in a freq map
        // should store how many tasks are left
        unordered_map<char, int> mp;
        for(auto task : tasks){
            mp[task]++;
        }

        int time = 0;

        // Store priority queue in LIKE
        // 5 - A
        // 2 - B
        priority_queue<pair<int, char>> pq;

        // after then store all the entries in a max heap this will help us decide which exact task should we first do (always do the largest freq one)
        for(auto &entry : mp){

            pq.push({entry.second, entry.first});
        }

        //now once we select some task we should ensure that we can only reinsert into the heap once the cooldown is down

        //lets use a queue to store the readyTime of the tasks
        // cooldown <task,  remaningTasks>>
        // Coold own stored like (5, (A, 2))
       queue<pair<int, pair<char, int>>> coolDown;


        while(!pq.empty() || !coolDown.empty()){
            time++;

            if(!pq.empty()){
                // keep executing the tasks until we ran out of all the tasks
                // keep in mind this is pretty distinct so like even if there are like multiple X and Y this only runs for 2 times
                auto [count, task] = pq.top();
                pq.pop();

                count--;
                // the job has existing tasks remaning
                if(count > 0){
                    coolDown.push({time + n, {task, count}});
                }


            }

            while(!coolDown.empty() && coolDown.front().first <= time){
                // cool down period of that job is done
                // we can now insert it into the maxheap
                auto [task, count] = coolDown.front().second;
                coolDown.pop();
                pq.push({count, task});
            }


        }

        return time;




    }
};
