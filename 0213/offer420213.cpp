//
// @ClassName offer420213
// @Description TODO
// @Date 2019/2/13 2:30 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class  Solution {
public:
    int maxSeqSum(vector<int> &vec) {
        if (vec.size() == 0) {
            return 0;
        }
        vector<int> dp(vec.size(), 0);
        dp[0] = vec[0];

        int res = 0;

        for (int i = 1; i < vec.size(); i++) {
           dp[i] = max(dp[i - 1] + vec[i],vec[i]);
           if (dp[i] >= res) {
               res = dp[i];
           }
        }

        return res;
    }

};


int main() {
    int arr[] = {6,-3,-2,7,-15,1,2,2};
    vector<int> vec(&arr[0], &arr[8]);

    Solution sol;
    cout << sol.maxSeqSum(vec) << endl;



    return 0;
}
