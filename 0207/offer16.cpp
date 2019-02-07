//
// @ClassName offer16
// @Description TODO
// @Date 2019/2/7 4:40 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution{
public:
    int myPow(int x, int y) {
        if (y == 0) {
            return 1;
        } else if (y < 0) {
            return ( 1 / x) * myPow(1/x, -(y + 1));
        } else {
            return y % 2 == 0 ? myPow(x * x, y / 2) :  x * myPow(x * x, y / 2);
        }
    }

};


int main() {
    Solution sol;

    cout << sol.myPow(2, 3) << endl;
    cout << sol.myPow(3, 2) << endl;
    cout << sol.myPow(2, 0) << endl;

    return 0;
}
