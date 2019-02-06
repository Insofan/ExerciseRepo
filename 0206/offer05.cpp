//
// @ClassName offer05
// @Description TODO
// @Date 2019/2/6 9:46 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    string replace(string str) {
        
        string res = "";
        
        for (int i = 0; i < str.length(); i++) {
            char x = str[i];
            if (x == ' ') {
                res += "%20";
                continue;
            }
            res += str[i];
        }

        return res;
    }
    
    
};


int main() {
    
    string str = "Hello world !";
    
    Solution solution;
    cout << solution.replace(str) << endl;

    return 0;
}
