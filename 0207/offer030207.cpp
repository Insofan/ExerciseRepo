//
// @ClassName offer030207
// @Description TODO
// @Date 2019/2/7 4:54 PM
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

    int arr[] = {8, 1, 2, 3, 4, 5, 6, 7, 0, 5};
    vector<int> vec(&arr[0], &arr[10]);
    Solution solution;
    int res   = solution.duplicate(vec);
    cout << res << endl;
    return 0;
}
