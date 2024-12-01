#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
public:
    int front;
    int rear;
    vector<int> v;
    int capacity;
    MyCircularDeque(int k) {
        // 此处需要多空出一个位置，否则无法区分队列已满和队列为空的情况
        // 若不添加空的位置，则队列已满和队列为空均是front==rear
        // 添加一个空的位置，则队列为空是front==rear，队列已满是(rear+1)%capacity==front,即rear的下一个元素为front代表队列已满
        // 取模是因为有可能rear指向数组中最后一位，此时rear+1若不取模，则永远不可能等于front，但是这种情况下若front为0也是队列已满
        capacity = k + 1;
        v = vector<int>(capacity, -1);
        // 指向队首元素
        front = 0;
        // 指向队尾元素的下一个索引，即若要获取队尾元素则v[rear-1]
        rear = 0;
    }

    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            v[front] = value;
            rear = (rear + 1) % capacity;
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
            v[front] = value;
        }
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            v[front] = value;
            rear = (rear + 1) % capacity;
        }
        else
        {
            v[rear] = value;
            rear = (rear + 1) % capacity;
        }
        return true;
    }

    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        if(isEmpty())
        {
            return -1;
        }
        return v[front];
    }

    int getRear() {
        if(isEmpty())
        {
            return -1;
        }
        return v[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

int main()
{
    MyCircularDeque circularDeque = MyCircularDeque(4); // 设置容量大小为3
    std::cout << circularDeque.insertFront(9) << std::endl;			        // 返回 true
    std::cout << circularDeque.deleteLast() << std::endl;			        // 返回 true
    std::cout << circularDeque.getRear() << std::endl;			        // 返回 true
    std::cout << circularDeque.getFront() << std::endl;			        // 已经满了，返回 false
    std::cout << circularDeque.getFront() << std::endl;			        // 已经满了，返回 false
    std::cout << circularDeque.deleteFront() << std::endl;  				// 返回 2
    std::cout << circularDeque.insertFront(6) << std::endl;				        // 返回 true
    std::cout << circularDeque.insertLast(5) << std::endl;			        // 返回 true
    std::cout << circularDeque.insertFront(9) << std::endl;			        // 返回 true
    std::cout << circularDeque.getFront() << std::endl;				// 返回 4
    std::cout << circularDeque.insertFront(6) << std::endl;				// 返回 4
    return 0;
}

