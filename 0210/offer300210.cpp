//
// @ClassName offer300210
// @Description TODO
// @Date 2019/2/10 9:29 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int value) {
        if (_dataStack.size() == 0) {
            _helperStack.push(value);
        } else {
            if (value > _helperStack.top()) {
                _helperStack.push(_helperStack.top());
            } else {
                _helperStack.push(value);
            }
        }
        _dataStack.push(value);
    }

    void pop() {
        _dataStack.pop();
        _helperStack.pop();
    }

    int top() {
        return _dataStack.top();
    }

    int min() {
        return _helperStack.top();
    }


private:
    stack<int> _dataStack;
    stack<int> _helperStack;
};



int main() {



    return 0;
}
