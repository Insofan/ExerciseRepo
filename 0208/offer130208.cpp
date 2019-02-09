//
// @ClassName offer130208
// @Description TODO
// @Date 2019/2/8 6:50 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int max, int row, int col) {

        vector<vector<bool> > visited(row, vector<bool>(col, false));
        int res  = helper(visited, max, 0, 0, row, col);
        return res;
    }

private:
    int helper(vector<vector<bool> > &visited, int max, int curRow, int curCol, int row, int col) {
        int res = 0;
        if (check(visited, max, curRow, curCol, row, col)) {
            visited[curRow][curCol] = true;
            res = 1 + helper(visited, max, curRow + 1, curCol, row, col) +
                  helper(visited, max, curRow - 1, curCol, row, col) +
                  helper(visited, max, curRow, curCol + 1, row, col) +
                  helper(visited, max, curRow, curCol - 1, row, col);
        }
        return res;
    }

    bool check(vector<vector<bool> > &visited, int max, int curRow, int curCol, int row, int col) {
        if (curRow >= 0 && curRow < row && curCol >= 0 && curCol < col && (getSum(curRow, curCol) <= max)&& (visited[curRow][curCol] ==
                false)) {
            return true;
        } else {
            return false;
        }
    }

    int getSum(int x, int y) {
        int sum = 0;

        while (x) {
            sum += x % 10;
            x /= 10;
        }

        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    cout << solution.movingCount(5, 10, 10) << endl;


    return 0;
}
