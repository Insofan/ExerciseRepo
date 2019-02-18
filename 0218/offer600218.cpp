//
// @ClassName offer600218
// @Description TODO
// @Date 2019/2/18 9:39 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, double> > nDice(int n) {
        vector<pair<int, double> > res;

        vector<vector<double> > dp(n + 1, vector<double>(6 * n + 1));

        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1 / 6.0;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * n; j++) {

                for ( int k = 0; k <= 6; k++) {
                    if (j > k) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
                dp[i][j] /= 6.0;
            }
        }

        for (int i = n; i <= 6 * n; i++) {
            res.push_back(make_pair(i, dp[n][i]));
        }
        return res;
    }
};


int main() {

    Solution sol;

    vector<pair<int, double> > res = sol.nDice(6);

    for (int i = 0; i < res.size(); i++) {
         cout << res[i].first << " : " << res[i].second << endl;
    }

    return 0;
}
