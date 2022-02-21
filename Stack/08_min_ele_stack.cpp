// while pushing if min element comes
// then insert 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack {
    public:
        stack<int> s;
        int minE;
    private:
        int getMin() {
            if (s.size() == 0) {
                return -1;
            }
            return minE;
        }



};

int main() {
    return 0;
}