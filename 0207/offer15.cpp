//
// @ClassName offer15
// @Description TODO
// @Date 2019/2/7 4:37 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int countOfBit(int num) {

        int res = 0;
        while  (num) {
            num &= num - 1;
            res++;
        }

        return res;
    }
};


int main() {
    int arg = 2;
    Solution sol;
    cout << sol.countOfBit(arg) << endl;

    arg = 4;
    cout << sol.countOfBit(arg) << endl;

    arg = 5;

    cout << sol.countOfBit(arg) << endl;
    arg = 7;

    cout << sol.countOfBit(arg) << endl;



    return 0;
}
