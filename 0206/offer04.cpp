//
// @ClassName offer04
// @Description TODO
// @Date 2019/2/6 9:27 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNum(vector< vector<int> > &matrix, int tar) {
        if (matrix.size() == 0) {
            return false;
        }

        int m = 0;
        int n = matrix[0].size() - 1;


        for (; m < matrix.size() && n >= 0;) {
            if (matrix[m][n] == tar) {
                return true;
            } else if (tar > matrix[m][n]) {
               m++;
            } else if ( tar < matrix[m][n]) {
                n--;
            }
        }

        return false;
    }
};


int main() {

    int arr1[] = {1, 3, 5, 7, 8};
    int arr2[] = {11, 13, 15, 17, 18};
    int arr3[] = {21, 23, 25, 27, 28};
    int arr4[] = {31, 33, 35, 37, 38};
    int arr5[] = {41, 43, 45, 47, 48};
    vector<int> vector1(&arr1[0], &arr1[5]);
    vector<int> vector2(&arr2[0], &arr2[5]);
    vector<int> vector3(&arr3[0], &arr3[5]);
    vector<int> vector4(&arr4[0], &arr4[5]);
    vector<int> vector5(&arr5[0], &arr5[5]);

    vector<vector<int> > matrix;
    matrix.push_back(vector1);
    matrix.push_back(vector2);
    matrix.push_back(vector3);
    matrix.push_back(vector4);
    matrix.push_back(vector5);

    Solution solution;
    bool res = solution.findNum(matrix, 35);
    cout << boolalpha << res << endl;

    res = solution.findNum(matrix, 36);
    cout << boolalpha << res << endl;

    res = solution.findNum(matrix, 43);
    cout << boolalpha << res << endl;
    return 0;
}
