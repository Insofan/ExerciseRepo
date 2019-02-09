//
// @ClassName offer110208
// @Description TODO
// @Date 2019/2/8 6:01 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rotateNum(vector<int> &vec) {

        int left = 0;
        int right = vec.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (vec[mid] > vec[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return vec[left];

    }
};


int main() {

    int arr[] = {10, 11, 6, 8, 9};

    vector<int> vec(&arr[0], &arr[5]);

    Solution sol;

    cout << sol.rotateNum(vec) << endl;

    return 0;
}
