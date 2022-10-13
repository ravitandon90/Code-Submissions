class DiningPhilosophers {
     Semaphore forks[] = new Semaphore[5];
     Semaphore allowMaxFour = new Semaphore(4);
    public DiningPhilosophers() {
        for(int i=0;i<5;i++)
        {
            forks[i] = //new ReentrantLock();
                new Semaphore(1);
        }
    }
    private void acquireLeftFork(int id,Runnable pickLeftFork,Runnable pickRightFork) throws InterruptedException
    {
        forks[id].acquire();
        pickLeftFork.run();
        forks[(id - 1) % 5].acquire(); 
        pickRightFork.run();
    }
     private void acquireRightFork(int id,Runnable pickLeftFork,Runnable pickRightFork) throws InterruptedException
    {
        forks[(id - 1) % 5].acquire(); 
         pickRightFork.run();
        forks[id].acquire();
         pickLeftFork.run();
    }
    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        
       int leftFork = philosopher;
        int rightFork = (philosopher + 4) % 5;
        
        allowMaxFour.acquire();
        
        forks[leftFork].acquire();
        pickLeftFork.run();
        forks[rightFork].acquire();
        pickRightFork.run();
        
        eat.run();
        
        allowMaxFour.release();
        
        putLeftFork.run();
        forks[leftFork].release();
        putRightFork.run();
        forks[rightFork].release();
        
        
        
        
        
        /*
            if (philosopher == 0) {
            acquireLeftFork(0,pickLeftFork,pickRightFork);
        } else {
            acquireRightFork(philosopher,pickLeftFork,pickRightFork);
        }
        eat.run();
        putLeftFork.run();
        forks[philosopher].release();
        putRightFork.run();
        forks[(philosopher + 1) % 5].release();*/
        
     /*   
        forks[(philosopher+(philosopher % 2)) % 5].acquire();
        forks[(philosopher + ((philosopher + 1) % 2))%5].acquire();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        forks[(philosopher+(philosopher % 2)) % 5].release();
        forks[(philosopher + ((philosopher + 1) % 2))%5].release();*/
    }
}