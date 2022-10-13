// https://leetcode.com/problems/the-dining-philosophers/

class DiningPhilosophers {
private:
    mutex mtxFork[5];
    mutex mtxTable;
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
		
        unique_lock<mutex> lckTable(mtxTable);
        unique_lock<mutex> lckForkLeft(mtxFork[left]);
        unique_lock<mutex> lckForkRight(mtxFork[right]);
        lckTable.unlock(); // after locking both forks, we can safely unlock table
        
        pickLeftFork(); pickRightFork(); eat(); putRightFork(); putLeftFork();
        // locks will be automatically released due to unique_lock RAII design
    }
};
