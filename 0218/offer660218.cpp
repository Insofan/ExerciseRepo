//
// @ClassName offer660218
// @Description TODO
// @Date 2019/2/18 10:13 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mutilVec(int n) {
        vector<int> res;
        int fromBegin = 1;
        int fromEnd = 1;
        
        for (int i = 0; i < n; i++) {
            fromBegin *= i;
            res[i] *=fromBegin;
        }
        
        for (int j = n - 1; j >= 0; j--) {
            fromEnd *= j;
            res[j] *= fromEnd;
        }

        return res;
    }

};


int main() {
    
    Solution sol;
    vector<int> res = sol.mutilVec(6);
    
    for ( int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
