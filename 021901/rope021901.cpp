//
// @ClassName rope021901
// @Description TODO
// @Date 2019/2/19 4:37 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cutRope(int n) {
        if (n <= 1) {
            return n;
        }

        if (n == 2) {
            return 1;
        }

        if (n == 3) {
            return 2;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        int      tmp = 0;
        int      max = 0;
        for (int i   = 4; i <= n; i++) {
            max = 0;
            for (int j = 1; j <= i / 2; j++) {
                tmp = dp[j] * dp[i - j];
                if (tmp > max) {
                    max = tmp;
                }
            }
            dp[i] = max;
        }
        return dp[n - 1];
    }
};


int main() {
    Solution sol;
    cout << sol.cutRope(10) << endl;
    return 0;
}
