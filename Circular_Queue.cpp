class MyCircularQueue {
private:
    vector<int> queue;
    int head, tail, capacity, size;

public:
    MyCircularQueue(int k) : queue(k), head(-1), tail(-1), capacity(k), size(0) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) head = 0;
        tail = (tail + 1) % capacity;
        queue[tail] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[head];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[tail];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
