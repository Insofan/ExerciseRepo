//
// @ClassName rotate021901
// @Description TODO
// @Date 2019/2/19 4:24 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rotateArr(vector<int> &vec) {
        int idx = binarySearch(vec);

        return vec[idx];
    }

private:
    int binarySearch(vector<int> &vec) {
        int l = 0;
        int r = vec.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (vec[mid] > vec[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};


int main() {

    int arr[] = {5, 6, 7, 0, 1, 2, 3, 4};
    vector<int> vec(&arr[0], &arr[8]);
    Solution sol;

    cout << sol.rotateArr(vec) << endl;

    return 0;
}
