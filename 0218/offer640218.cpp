//
// @ClassName offer640218
// @Description TODO
// @Date 2019/2/18 10:04 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nSum(int n) {
        int sum = n;

        (n > 0) && (sum += nSum(n- 1));
        return sum;
    }
};


int main() {
    Solution sol;
    cout << sol.nSum(7) << endl;
    return 0;
}
