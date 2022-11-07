// Problem statement: Implement a stack using an array.
// Note: Stack is a data structure that follows 
// the Last In First Out (LIFO) rule.



#include <iostream>
using namespace std;

class Stack {
        int *arr;
        int capacity;
        int currSize;
    public:
        Stack(int size) {
            arr = new int[size];
            capacity = size;
            currSize = 0;
        }

        void push(int x) {
            if (currSize == capacity) {
                cout << "Stack Overflow";
                return;
            }
            arr[currSize++] = x;
        }

        void pop() {
            if (currSize == 0) {
                cout << "Stack Underflow";
                return;
            }
            currSize--;
        }

        int top() {
            if (currSize==0) {
                return -1;
            }
            return arr[currSize-1];
        }

        int size() {
            return currSize;
        }
};

int main() {

    Stack s(10);
    s.push(10);
    s.push(5);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    cout << s.size();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}