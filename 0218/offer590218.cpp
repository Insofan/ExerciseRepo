//
// @ClassName offer59
// @Description TODO
// @Date 2019/2/18 9:26 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

struct MonitonicQueue {

    MonitonicQueue(){};

    void push(int x) {

        while (!dq.empty() && x >= dq.back()) {
            dq.pop_back();
        }

        dq.push_back(x);
    }

    int max() {
        cout << " max count " << dq.size() << endl;
        return dq.front();
    }

    void pop(){
//        dq.pop_back();
        dq.pop_front();
    }

private:
    deque<int> dq;
};


class Solution {
public:
    vector<int> slideWinMaxNum(vector<int> &vec, int k) {
        vector<int> res;
        MonitonicQueue mq;

        for (int i = 0; i < vec.size(); i++) {
            mq.push(vec[i]);
            if (i - k + 1 >= 0) {
                res.push_back(mq.max());
                if (vec[i - k + 1] == mq.max()) {
                    mq.pop();
                }
            }
        }
        return res;
    }
};


int main() {
    int arr[] = {2,3,4,2,6,2,5,1};

    vector<int> vec(&arr[0], &arr[8]);
    Solution sol;

    vector<int> res = sol.slideWinMaxNum(vec, 3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
