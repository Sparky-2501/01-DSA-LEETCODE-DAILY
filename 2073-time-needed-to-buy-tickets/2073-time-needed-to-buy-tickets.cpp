class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
         queue<int> q;
        /*approach
        put all index into queue->loop until (selected person k has tickets 0)
        decrease the tickets[q.front()] until we get 0 and the person we want with all ticket
        */
        // Putting all people into the queue
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;
        while (!q.empty()) {
            int person = q.front();
            q.pop();

            // Buy one ticket
            tickets[person]--;
            time++;

            // If person k has bought their last ticket
            if (person == k && tickets[person] == 0) {
                return time;
            }

            // If they still need tickets, go to the back
            if (tickets[person] > 0) {
                q.push(person);
            }
        }

        return time;
    }
};