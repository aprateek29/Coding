#include <iostream>
#include <stack>
using namespace std;

class CustomStack {
    stack<int> s;
    int minEle;
    public:

        void push (int x){
            if (s.size() == 0) {
                minEle = x;
                s.push(x);
            } else {
                if (x >= minEle) {
                    s.push(x);
                } else {
                    s.push(2*x - minEle);
                    minEle = x;
                }
            }
        }

        void pop () {
            if (s.size() && s.top() < minEle) {
                minEle = 2 * minEle - s.top();
            }
            s.pop();
        }

        int top () {
            if (s.size() == 0) {
                return -1;
            } else if (s.top() >= minEle) {
                return s.top();
            } else {
                return minEle;
            }
        }

        int getMin() {
            if (s.size() == 0) {
                return -1;
            }
            return minEle;
        }
};

int main() {

    CustomStack s;
    s.push(20);
    s.push(30);
    s.push(10);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;

    return 0;
}