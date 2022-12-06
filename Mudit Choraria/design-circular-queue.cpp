class MyCircularQueue {
public:
    vector<int> que;
    int head = 0, tail, capacity, size = 0;
    MyCircularQueue(int k) {
        que.resize(k, -1);
        capacity = k;
        tail = k - 1;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        tail = ++tail % capacity;
        que[tail] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        head = ++head % capacity;
        --size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : que[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : que[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */