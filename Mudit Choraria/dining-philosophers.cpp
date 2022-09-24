class DiningPhilosophers {
public:
    mutex mtx[5];
    DiningPhilosophers() {}
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        if(philosopher % 2 == 0){
            mtx[right].lock(); // lock right before left
            mtx[left].lock();
            pickLeftFork(); pickRightFork();
        }
		else{
            mtx[left].lock(); // lock left before right
            mtx[right].lock();
            pickLeftFork(); pickRightFork();
        }
        
        eat(); putRightFork(); putLeftFork();
        mtx[left].unlock();
        mtx[right].unlock();
    }
};