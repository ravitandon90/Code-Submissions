class DiningPhilosophers {
private:
    mutex mtx[5];
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        unique_lock<mutex> lck1(mtx[left], defer_lock); // defer_lock: init lck1 without locking mtx
        unique_lock<mutex> lck2(mtx[right], defer_lock);
        
        if(philosopher % 2 == 0){
            lck1.lock(); // do NOT use std::lock(lck1, lck2)
            lck2.lock();
            pickLeftFork(); pickRightFork();
        }
		else{
            lck2.lock();
            lck1.lock();
            pickLeftFork(); pickRightFork();
        }
        eat(); putRightFork(); putLeftFork();
        // lck1 & lck2 are auto released after this line
    }
};