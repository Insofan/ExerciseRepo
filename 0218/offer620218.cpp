//
// @ClassName offer620218
// @Description TODO
// @Date 2019/2/18 9:58 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastInCircle(int m, int n) {
        int res = 1;

        for (int i = 2; i <=m; i++) {
            res  = (res + m) % i;
        }

        return res;
    }
};


int main() {
    Solution sol;
    cout << sol.lastInCircle(5, 3);

    return 0;
}
