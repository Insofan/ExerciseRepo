//
// @ClassName test0213
// @Description TODO
// @Date 2019/2/13 3:09 PM
// @Created by Insomnia
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty()) {
            return "0";
        }

        sort(nums.begin(), nums.end(), [](int x, int y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });

        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }

        return res[0] == '0' ? "0" : res;
    }
};

vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        tempVec.push_back(x);
    }
    return tempVec;
}

int main() {
    int arr[] = {32, 3, 321};
    vector<int> vec(&arr[0], &arr[3]);
    Solution solution;
//    cout << solution.minNumOffer(vec) << endl;
//    cout << solution.minNumOffer2(vec) << endl;


    return 0;
}
