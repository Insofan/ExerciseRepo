//
// @ClassName RobotPath
// @Description TODO
// @Date 2019/2/19 2:46 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool> > matrix(rows + 1, vector<bool>(cols + 1, false));

        int res = helper(matrix, threshold, rows, cols, 0, 0);
        return res;
    }

private:

    int helper(vector<vector<bool> > &matrix, int max, int rows, int cols, int curRow, int curCol) {

        int res = 0;

        if (check(matrix, max, rows, cols, curRow, curCol)) {
            matrix[curRow][curCol] = true;
            res = 1 + helper(matrix, max, rows, cols, curRow + 1, curCol)
                    + helper(matrix, max, rows, cols, curRow - 1, curCol)
                      + helper(matrix, max, rows, cols, curRow , curCol + 1)
                        + helper(matrix, max, rows, cols, curRow , curCol - 1);
        }

        return res;
    }

    bool check(vector<vector<bool> > &matrix, int max, int rows, int cols, int curRow, int curCol) {
        if (curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols && (matrix[curRow][curCol] == false) && (getSum(curRow, curCol) <= max)) {
            return true;
        }
        return false;
    }

    int getSum(int x, int y) {
        int sum = 0;
        while (x) {
            int tmp = x % 10;
            sum += tmp;
            x /= 10;
        }

        while (y) {
            int tmp = y % 10;
            sum += tmp;
            y /= 10;
        }

        return sum;
    }

};
int main() {

    Solution sol;

    cout << sol.movingCount(10, 10 ,18) << endl;

    return 0;
}
