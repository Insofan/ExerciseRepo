//
// @ClassName offer310210
// @Description TODO
// @Date 2019/2/10 9:42 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool stackOrder(vector<int> &pushOrd, vector<int> &popOrd) {
        stack<int> myStack;

        int j = 0;
        for (int i = 0; i < pushOrd.size(); i++) {
            myStack.push(pushOrd[i]);

            while (!myStack.empty() && myStack.top() == popOrd[j]) {
                myStack.pop();
                j++;
            }
        }

        return myStack.size() == 0;
    }
};


int main() {
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {4,5,3,2,1};
    int arr3[] = {4,3,5,1,2};

    vector<int> vec1(&arr1[0], &arr1[5]);
    vector<int> vec2(&arr2[0], &arr2[5]);
    vector<int> vec3(&arr3[0], &arr3[5]);

    Solution sol;
    cout << boolalpha<< sol.stackOrder(vec1, vec2) << endl;
    cout << boolalpha<< sol.stackOrder(vec1, vec3) << endl;


    return 0;
}
