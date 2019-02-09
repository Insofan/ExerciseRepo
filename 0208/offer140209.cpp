//
// @ClassName offer140209
// @Description TODO
// @Date 2019/2/9 3:38 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRope(int rope) {
        if (rope == 0) {
            return 0;
        }

        if (rope == 1 || rope == 2) {
            return 1;
        }

        vector<int> dp(rope + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        int max;
        int tmp;
        for (int i = 4; i <= rope; i++) {
            max = 0;
            for (int j = 0; j <= i / 2; j++) {
                int tmp = dp[j] * dp[i - j];
                if (tmp > max) {
                    max = tmp;
                }
            }
            dp[i] = max;
        }
        return dp[rope];
    }
};


int main() {
    Solution solution;

    cout << "8 : " << solution.countRope(8) << endl;
    cout << "6 : " << solution.countRope(6) << endl;
    cout << "13 : " << solution.countRope(13) << endl;



    return 0;
}
