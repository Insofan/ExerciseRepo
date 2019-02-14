//
// @ClassName offer480214
// @Description TODO
// @Date 2019/2/14 4:52 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int longestSubStr(string str) {
        int res;

        int first = 0;
        int last = 0;

        set<char> mySet;

        for (int i= 0; i < str.length(); i++) {
//            mySet.insert(str[i]);
//            if (mySet)
        }

        return res;
    }
};


int main() {
    string str = "arabcacfr";

    Solution sol;

    cout << sol.longestSubStr(str) << endl;

    return 0;
}
