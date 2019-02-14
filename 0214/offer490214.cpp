//
// @ClassName offer490214
// @Description TODO
// @Date 2019/2/14 4:58 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isUglyNum(int num) {

        if ( num == 1 || num == 2 || num == 3 || num == 5) {
            return true;
        }


        for (int i = 2; i < 6; i++) {
            while (num % i == 0) {
                num /= i;
            }
        }


        return num == 1;
    }

};


int main() {

    Solution sol;

    cout << boolalpha << sol.isUglyNum(2) << endl;
    cout << boolalpha << sol.isUglyNum(12) << endl;
    cout << boolalpha << sol.isUglyNum(21) << endl;
    cout << boolalpha << sol.isUglyNum(14) << endl;
    cout << boolalpha << sol.isUglyNum(20) << endl;


    return 0;
}
