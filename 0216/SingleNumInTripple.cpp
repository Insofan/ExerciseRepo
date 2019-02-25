// 
// @ClassName SingleNumInTripple
// @Description TODO
// @Date 19-2-16 下午11:10
// @Created by Insomnia
//
//1, 2, 1, 2, 1, 2, 7, 只有一个数字出现一次 剩下出现三次

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int singleNumInVec(vector<int> &vec) {


    }

};

int main() {
    int arr[] = {1, 2, 1, 2, 1, 2, 7};
    vector<int> vec(&arr[0], &arr[7]);

    Solution sol;
    cout << sol.singleNumInVec(vec) << endl;
    return 0;
}