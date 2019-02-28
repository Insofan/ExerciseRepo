// 
// @ClassName reversestr0228
// @Description TODO
// @Date 19-2-28 下午10:04
// @Created by Insomnia
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string s = str;
        reverse(s.begin(), s.end());

        int i = 0;
        int j = 0;

        while (i < s.length()) {
            while (i < s.length() && s[i] != ' '){
                i++;
            }
            reverse(s.begin() + j, s.begin() + i);
            j = ++i;
            //i++;
        }


        return s;
    }
};

int main() {

    string s = "the sky is blue";

    Solution sol;

    cout << sol.ReverseSentence(s) << endl;
    return 0;
}