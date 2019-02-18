//
// @ClassName offer580218
// @Description TODO
// @Date 2019/2/18 9:23 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseStr(string &str) {
        int i = 0;
        int j = str.length() - 1;

        while (i < j) {
            swap(str[i++], str[j--]);
        }
    }
};
    

int main() {
    string str = "Hello world!";

    Solution sol;
    cout << str << endl;
    sol.reverseStr(str);
    cout << str << endl;

    return 0;
}
