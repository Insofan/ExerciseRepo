//
// @ClassName offer290210
// @Description TODO
// @Date 2019/2/10 9:09 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void printMatrix(vector<vector<int> > &matrix) {

        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++) {
                cout << matrix[rowBegin][j] << " ";
            }
            rowBegin++;

            for (int i = rowBegin; i <= rowEnd; i++) {
                cout << matrix[i][colEnd] << " ";
            }
            colEnd--;

            if (rowBegin <= rowEnd) {
                for (int j = colEnd; j >= colBegin; j--) {
                    cout << matrix[rowEnd][j] << " ";
                }
            }
            rowEnd--;

            if (colBegin<=colEnd) {
               for (int i = rowEnd; i >= rowBegin; i--) {
                  cout << matrix[i][colBegin] << " ";
               }
            }
            colBegin++;
        }

        return;
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

    Solution sol;
    sol.printMatrix(matrix);


    return 0;
}
