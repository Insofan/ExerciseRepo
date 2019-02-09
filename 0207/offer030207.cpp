//
// @ClassName offer030207
// @Description TODO
// @Date 2019/2/7 4:54 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    int duplicate(vector<int> &vec) {
        for (int i = 0; i < vec.size(); i++) {
            while (vec[i] != i) {
                if (vec[i] == vec[vec[i]]) {
                    return vec[i];
                }

                swap(vec[i], vec[vec[i]]);
            }
        }
        return -1;
    }
    priority_queue<int, vector<int> , greater<int> > smallQueue;
};

int main() {

    int arr[] = {8, 1, 2, 3, 4, 5, 6, 7, 0, 5};
    vector<int> vec(&arr[0], &arr[10]);
    Solution solution;
    int res   = solution.duplicate(vec);
    cout << res << endl;

    solution.smallQueue.push(1);
    solution.smallQueue.push(2);
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.push(3);
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.push(0);
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.pop();
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.pop();
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.pop();
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.pop();
    cout << solution.smallQueue.top() << endl;
    solution.smallQueue.pop();
    cout << solution.smallQueue.top() << endl;
    return 0;
}
