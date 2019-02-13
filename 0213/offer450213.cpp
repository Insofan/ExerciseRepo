//
// @ClassName offer450213
// @Description TODO
// @Date 2019/2/13 2:42 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
//    int minNum(vector<int> vec) {
//        sort(vec.begin(), vec.end(),[](int x, int y) {
//            return (to_string(x) + to_string(y)) > (to_string(y) + to_string(x));
//        });
//        sort(vec.begin(), vec.end(), [](int x, int y) {
//            return (to_string(x) + to_string(y)) < (to_string(y) + to_string(x));
//        });

//        string res;
//
//        for (int i = 0; i < vec.size(); i++) {
//            res += to_string(vec[i]);
//        }
//
//        return stoi(res);
//    }

    int minNum2(vector<int> vec) {
        string res;
        sort(vec.begin(), vec.end(), [](int x, int y) {
            return (to_string(x) + to_string(y)) < (to_string(y) + to_string(x));
        });
        for (int i = 0; i < vec.size(); ++i) {
            res += to_string(vec[i]);
        }

        return res[0] == '0' ? 0 : stoi(res);
    }
};

int main() {
    int arr[] = {3, 32, 321};
    vector<int> vec(&arr[0], &arr[3]);

    Solution sol;
    cout << sol.minNum2(vec) << endl;


    return 0;
}
