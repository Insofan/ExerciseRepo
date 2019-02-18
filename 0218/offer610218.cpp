//
// @ClassName offer610218
// @Description TODO
// @Date 2019/2/18 9:48 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &vec) {
        int jokerCount = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) {
                jokerCount++;
            }
        }

        sort(vec.begin(), vec.end());

        int gap = 0;
        for (int i = jokerCount + 1; i < vec.size(); i++) {
            gap += vec[i] - vec[i - 1] - 1;
        }

        return gap > jokerCount ? false : true;
    }
};

int main() {
    int arr[] = {5, 7, 6, 0, 1};

    vector<int> vec(&arr[0], &arr[5]);

    Solution sol;

    cout << boolalpha << sol.isStraight(vec) << endl;

    return 0;
}
