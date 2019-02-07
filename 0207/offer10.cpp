//
// @ClassName offer10
// @Description TODO
// @Date 2019/2/7 4:15 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        vector<int> dp(n, 0);

        dp[0] = 0;
        dp[1] = 1;

        for ( int i = 2; i <= n;i++){
           dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int frog(int n) {

        if ( n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }

        vector<int> dp(n + 1,0);

        dp[1] = 1;
        dp[2] = 2;

        for ( int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {

    Solution sol;
    cout << sol.fib(7) << endl;
    cout << sol.frog(7) << endl;




    return 0;
}
