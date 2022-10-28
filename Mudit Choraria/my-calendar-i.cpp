class MyCalendar {
private:
    map<int, int> timeline;
    const int maxValidBooking = 1;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        int curr = 0, res = 0;
        timeline[start]++;
        timeline[end]--;
        for(auto& [_, count] : timeline) {
            curr += count;
            if(curr > maxValidBooking) {
                if(--timeline[start] == 0) {
                    timeline.erase(start);
                }
                if(++timeline[end] == 0) {
                    timeline.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */