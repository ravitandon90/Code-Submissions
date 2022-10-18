// Solution 3: Limit 4 philosophers to eat at same time
class Semaphore {
private:
	int count;
    mutex mtx;
    condition_variable cv;
	
public:
    Semaphore(int n = 0) : count(n) { }
    void Set(int n) { count = n; }
    void Signal() {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void Wait() {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&](){ return count > 0; }); // standard format of wait() lambda expression
        --count;
    }
};

class DiningPhilosophers {
private:
    mutex mtx[5];
    Semaphore sem;
    
public:
    DiningPhilosophers() { sem.Set(4); }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        sem.Wait(); // if there are 4 philosophers eating, thread will wait here

        unique_lock<mutex> lckLeft(mtx[left]);
        unique_lock<mutex> lckRight(mtx[right]);
        
        pickLeftFork(); pickRightFork(); eat(); putRightFork(); putLeftFork();
        
        lckLeft.unlock();
        lckRight.unlock();

        sem.Signal(); // finish eating, release 1 spot for other philosophers
    }
};
