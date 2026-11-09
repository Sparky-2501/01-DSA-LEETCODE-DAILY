class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //k , arrival[i] , load[i]
        /*i%k
        0 0
        1 3
        2 2
        3 1
        */
        set<int> available;

        // {finishTime, serverIndex}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        for (int i = 0; i < arrival.size(); i++) {

            // free servers that have completed their work
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            if (available.empty()) {
                continue;
            }

            // preferred server
            int preferred = i % k;

            // find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // circular search
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // assign request
            available.erase(it);

            count[server]++;

            //busy server 
            busy.push({arrival[i] + load[i], server});
        }

        // maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;

    }
};