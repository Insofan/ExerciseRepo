// 
// @ClassName offer310212
// @Description TODO
// @Date 19-2-12 下午4:03
// @Created by Insomnia
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool stackOrder(vector<int> &pushVec, vector<int> &popVec) {
        stack<int> myStack;
        int j = 0;
        for (int i = 0; i < pushVec.size();i++) {
            myStack.push(pushVec[i]);
            while (!myStack.empty() && myStack.top() == popVec[j]) {
                myStack.pop();
                j++;
            }
        }

        return myStack.empty();
    }

};

int main() {
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {4,5,3,2,1};
    int arr3[] = {4,3,5,1,2};
    vector<int> pushVec(&arr1[0], &arr1[5]);
    vector<int> popVec1(&arr2[0], &arr2[5]);
    vector<int> popVec2(&arr3[0], &arr3[5]);

    Solution sol;

    cout << boolalpha << sol.stackOrder(pushVec, popVec1) << endl;
    cout << boolalpha << sol.stackOrder(pushVec, popVec2) << endl;

    return 0;
}