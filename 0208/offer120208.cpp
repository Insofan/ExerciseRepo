//
// @ClassName offer120208
// @Description TODO
// @Date 2019/2/8 6:11 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Soluiton {
public:

    bool wordSearch(vector<vector<char> > &matrix, string str) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (helper(matrix, str,i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool helper(vector<vector<char> > &matrix,string &str, int m, int n, int idx) {
        if (idx == str.size()) {
            return true;
        }

        if (m < 0 || m >= matrix.size() || n < 0 || n >= matrix[m].size()) {
            return false;
        }

        if (matrix[m][n] != str[idx]) {
            return false;
        }

        matrix[m][n] = '*';

        bool res = (helper(matrix, str, m + 1, n, idx + 1) ||
                    helper(matrix, str, m - 1, n, idx + 1) ||
                    helper(matrix, str, m, n + 1, idx + 1) ||
                    helper(matrix, str, m, n - 1, idx + 1));

        matrix[m][n] = str[idx];


        return res;
    }

};


int main() {
    char a1[] = {'A','B','C','E'};
    char a2[] = {'S','F','C','S'};
    char a3[] = {'A','D','E','E'};

    vector<char> b1(&a1[0], &a1[4]);
    vector<char> b2(&a2[0], &a2[4]);
    vector<char> b3(&a3[0], &a3[4]);

    vector<vector<char> > matrix;

    matrix.push_back(b1);
    matrix.push_back(b2);
    matrix.push_back(b3);

//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[i].size(); j++) {
//            cout << matrix[i][j] << ' ';
//        }
//    }
    Soluiton sol;

    cout << boolalpha << sol.wordSearch(matrix, "ABCCED") << endl;
    cout << boolalpha << sol.wordSearch(matrix, "SEE") << endl;
    cout << boolalpha << sol.wordSearch(matrix, "ABCB") << endl;

    return 0;
}
