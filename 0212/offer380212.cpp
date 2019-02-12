// 
// @ClassName offer380212
// @Description TODO
// @Date 19-2-12 下午9:42
// @Created by Insomnia
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        //set<string> resSet;
        vector<string> res;

        string tmpStr = "";
        generate(tmpStr, str, 0, res);
        return res;
    }

    void generate(string &tmpStr,string str, int i ,vector<string> &res) {
        if (i >= str.length()) {
            return;
        }

        tmpStr += str[i];

        res.push_back(tmpStr);
        generate(tmpStr, str, i + 1, res);
        tmpStr.pop_back();
        generate(tmpStr, str, i + 1, res);
    }


};

class Solution2 {
public:
    vector<string> permute(string str) {
        vector<string> res;
        if (str.length() == 0) {
            return res;
        }
        generate(0,  str, res);
        return res;
    }
private:
    void generate(int begin,string str, vector<string> &res) {
        if (begin >= str.length()) {
            res.push_back(str);
            return;
        }

        for (int i = begin; i < str.length(); i++) {
            if (i == begin || str[i] != str[begin]) {
               swap(str[i], str[begin]);
               generate(begin + 1, str, res);
               swap(str[begin], str[i]);
            }
        }
    }
};

int main() {
    string str = "abc";
    Solution sol;
    vector<string> res = sol.Permutation(str);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    Solution2 sol2;
    vector<string> res2 = sol2.permute(str);
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " ";
    }
    cout << endl;
    return 0;
}

