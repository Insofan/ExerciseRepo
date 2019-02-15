//
// @ClassName offer530215
// @Description TODO
// @Date 2019/2/15 2:05 PM
// @Created by Insomnia
//

//输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4.
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchNumInSortArr(vector<int> &vec, int tar) {
        int idx1 = helper(vec, tar);
        int idx2 = helper(vec, tar + 1);

        int res = 0;
        if (idx1 >= 0 && idx1 < vec.size() && idx2 - 1 >= 0  && idx2 - 1 < vec.size()) {
            if ((idx2 - idx1) > 0) {
                res = idx2 - idx1 ;
            } else {
                res =1;
            }
        }


        return res;
    }

private:
    int helper(vector<int> &vec, int tar) {

        int l = 0;
        int r = vec.size() - 1;

        while  ( l < r) {
            int  mid = (l + r) / 2;

            if (vec[mid] >= tar) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

};

int main() {

    int arr[8] = {1, 2, 3, 3, 3, 3, 4, 5};

    vector<int> vec(&arr[0], &arr[8]);

    Solution sol;

    cout << sol.searchNumInSortArr(vec, 5) << endl;


    return 0;
}
