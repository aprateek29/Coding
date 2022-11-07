#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int start;
    int end;
    public:
        Queue(int size) {
            capacity = size;
            arr = new int[size];
            end = -1;
            start = -1;
        }

        void push(int x) {
            if (start+1 == capacity) {
                cout << "Queue Overflow";
                return;
            }
            arr[++start] = x;
        }

        void pop() {
            if (end == start) {
                cout << "Queue Underflow";
                return;
            }
            end++;
        }

        int front() {
            if (start == end) {
                return -1;
            }
            return arr[start];
        }
};

int main() {

    Queue q(5);
    q.push(2);
    q.pop();
    cout << q.front();
    return 0;
}