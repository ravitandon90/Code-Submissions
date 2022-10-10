// Solution 1: Lock the table then pick up both forks together
class DiningPhilosophers {
private: 
    mutex fork[5]; // size = 5 bcoz we have 5 Philosophers
    mutex table;
    
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;
		
        unique_lock<mutex> lckTable(table); // consider 1 Philosophers at a time
        unique_lock<mutex> lckForkLeft(fork[left]); // left fork locked
        unique_lock<mutex> lckForkRight(fork[right]); // right fork locked
        
        lckTable.unlock(); // after locking both forks, we can safely unlock table 
        
        pickLeftFork(); 
        pickRightFork(); 
        eat(); 
        putRightFork(); 
        putLeftFork();
        // locks will be automatically released due to unique_lock RAII design
		
    }
};
