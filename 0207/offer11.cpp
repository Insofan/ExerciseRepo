//
// @ClassName offer11
// @Description TODO
// @Date 2019/2/7 4:24 PM
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
             int mid = (left + right ) / 2;

             if (vec[left] <= vec[mid]) {
                 left = mid + 1;
//                 right = mid - 1;
             } else if (vec[right] < vec[mid]) {
                 right = mid - 1;
//                 left = mid + 1;
             }
        }

        return vec[left];
    }

};


int main() {

    int arr[] = {3, 4, 5, 1, 2};

    vector<int> vec(&arr[0], &arr[5]);

    Solution sol;

    cout << sol.rotateNum(vec) << endl;

    return 0;
}
