class SmallestInfiniteSet {
    int next = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> added;

public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            added.erase(num);
            return num;
        }
        return next++;
    }

    void addBack(int num) {
        if (num < next && !added.count(num)) {
            pq.push(num);
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */