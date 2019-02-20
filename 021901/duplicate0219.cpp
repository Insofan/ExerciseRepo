//
// @ClassName duplicate0219
// @Description TODO
// @Date 2019/2/19 4:18 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

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

};


int main() {

    int arr[] = {2,3,1,0,2,5,3};
    vector<int> vec(&arr[0], &arr[7]);
    Solution sol;
    cout << sol.duplicate(vec);

    return 0;
}
