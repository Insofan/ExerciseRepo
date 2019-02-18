//
// @ClassName offer630218
// @Description TODO
// @Date 2019/2/18 10:00 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfile(vector<int> &vec) {
        int minPrice = INT32_MAX;
        int maxPro = INT32_MIN;

        for (int i = 0; i < vec.size(); i++) {
            minPrice = min(minPrice, vec[i]);
            maxPro = max(maxPro, vec[i] - minPrice);
        }

        return maxPro;
    }
};


int main() {
    int arr[] = {9,11,8,5,7,12,16,14};

    vector<int> vec(&arr[0], &arr[8]);

    Solution sol;

    cout << sol.maxProfile(vec);

    return 0;
}
