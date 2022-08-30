class SeatManager {
private:
    int num = 0;
    priority_queue<int, vector<int>, greater<int>> unreservedSeats;
public: 
    SeatManager(int n) {}
    
    int reserve() {
        // if no seats are unreserved, simply increase the counter
        if(unreservedSeats.empty()) {
            return ++num;
        }
        
        // if any seat was unreserved, lets pick it from pq
        int seatReserved = unreservedSeats.top();
        unreservedSeats.pop();
        return seatReserved;
    }
    
    void unreserve(int seatNumber) {
        unreservedSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */