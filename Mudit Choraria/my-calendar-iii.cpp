class MyCalendarThree {
private:
    map<int, int> timeline;
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        int curr = 0, res = 0;
        timeline[start]++;
        timeline[end]--;
        for(auto& [_, count] : diff) {
            curr += count;
            res = max(res, curr);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */