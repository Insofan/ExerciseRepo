//
// @ClassName offer560215
// @Description TODO
// @Date 2019/2/15 2:35 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int countOfNum(vector<int> &vec) {
        int res  = 1;

        for (int i = 0; i < vec.size(); i++) {
            res ^= vec[i];
        }

        return res;
    }
};


int main() {

    int arr[] = {2, 4, 3, 6, 3, 2, 5};

    vector<int> vec(&arr[0], &arr[7]);

    Solution sol;

    cout << sol.countOfNum(vec) << endl;

    return 0;
}
