//
// @ClassName offer09
// @Description TODO
// @Date 2019/2/7 4:07 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class  MyQueue{
public:

    void push(int x) {
        if (_data.size() == 0) {
            _data.push(x);
        } else {
            while (_data.size()) {
                _tmp.push(_data.top());
                _data.pop();
            }
            _data.push(x);

            while (_tmp.size()) {
                _data.push(_tmp.top());
                _tmp.pop();
            }
        }

    }
    void pop() {
        _data.pop();
    }

    int front() {
        if (_data.size()) {
            return _data.top();
        } else {
            return NULL;
        }
    }

private:

    stack<int> _data;
    stack<int> _tmp;

};


int main() {
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);

    cout << myQueue.front() << endl;
    myQueue.pop();
    cout << myQueue.front() << endl;
    myQueue.push(3);
    cout << myQueue.front() << endl;
    myQueue.pop();
    myQueue.pop();
    cout << myQueue.front() << endl;
    cout << myQueue.front() << endl;



    return 0;
}
