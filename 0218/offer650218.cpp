//
// @ClassName offer650218
// @Description TODO
// @Date 2019/2/18 10:09 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int sum(int a, int b) {
        return b == 0 ? a : sum(a ^ b, (a & b) << 1);
    }
};


int main() {
    Solution sol;
    cout << sol.sum(1, 3) << endl;

    return 0;
}
