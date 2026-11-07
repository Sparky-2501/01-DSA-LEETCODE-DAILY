
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // prio queue
        //  available servers: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            available;

        // busy servers: {freeTime, weight, index}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        // initially all servers are available
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // release all servers that are free
            while (!busy.empty() && get<0>(busy.top()) <= time) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // no server is available, wait
            if (available.empty()) {

                time = get<0>(busy.top());

                // release all servers free at this time
                while (!busy.empty() && get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // assign task and update server's free time
            busy.push({time + tasks[i], weight, index});
        }
        return ans;
    }
};
