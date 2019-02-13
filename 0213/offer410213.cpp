//
// @ClassName offer410213
// @Description TODO
// @Date 2019/2/13 1:59 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (largeQue.size() == 0) {
            largeQue.push(num);
        } else if (largeQue.size() > smallQue.size()) {
            if (num < largeQue.top()) {
                smallQue.push(largeQue.top());
                largeQue.pop();
                largeQue.push(num);
            } else {
                smallQue.push(num);
            }
        } else if (smallQue.size() > largeQue.size()) {
            if (num < smallQue.top()) {
                largeQue.push(num);
            } else {
                largeQue.push(smallQue.top());
                smallQue.pop();
                smallQue.push(num);
            }
        } else {
            if (num < largeQue.top()) {
                largeQue.push(num);
            } else {
                smallQue.push(num);
            }
        }

    }

    double findMedian() {

        int size = smallQue.size() + largeQue.size();
        if (size % 2 == 0) {
            return (smallQue.top() + largeQue.top()) / 2.0;
        } else {
            return smallQue.size() > largeQue.size() ? smallQue.top() : largeQue.top();
        }

    }

private:
    priority_queue<int, vector<int> ,greater<int> > smallQue;
    priority_queue<int, vector<int> > largeQue;
};


int main() {

    return 0;
}
