class MyCircularDeque {
public:
    vector<int> que;
    int head = 0, tail, capacity, size = 0;
    MyCircularDeque(int k) {
        que.resize(k, -1);
        capacity = k;
        tail = k - 1;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        head = (--head + capacity) % capacity;
        que[head] = value;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        tail = ++tail % capacity;
        que[tail] = value;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        head = ++head % capacity;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        tail = (--tail + capacity) % capacity;
        --size;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : que[head];
    }
    
    int getRear() {
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */