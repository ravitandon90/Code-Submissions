class DiningPhilosophers {

public:
    mutex person[5];
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        if(philosopher % 2 == 0){
            person[right].lock(); 
            person[left].lock();
            pickLeftFork(); 
            pickRightFork();
        }
		else{
            person[left].lock(); 
            person[right].lock();
            pickLeftFork(); 
            pickRightFork();
        }
        
        eat(); 
        putRightFork(); 
        putLeftFork();
        person[left].unlock();
        person[right].unlock();
		
    }
};