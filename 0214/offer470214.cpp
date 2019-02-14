//
// @ClassName offer470214
// @Description TODO
// @Date 2019/2/14 4:32 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxGift(vector<vector<int> > &vec) {
        int m = vec.size();
        if (vec.empty()) {
            return  -1;
        }
        int n = vec[0].size();

        vector<vector<int> > dp(m , vector<int>(n, 0));

        dp[0][0] = vec[0][0];
        for (int i = 1; i < m; i++) {
           dp[i][0] = dp[i - 1][0] + vec[i][0];
        }

        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + vec[0][i];
        }
        helper(1, 1,vec, dp);

        return dp[m - 1][n- 1];
    }

    void helper(int m ,int n,vector<vector<int> > &vec, vector<vector<int> > &dp) {

        if (m >= vec.size() || n >= vec[0].size()) {
            return;
        }

        dp[m][n] = max(dp[m - 1][n], dp[m][n - 1]) + vec[m][n];
        helper(m+1, n, vec, dp);
        helper(m, n + 1, vec, dp);

    }
};


int main() {
    int arr1[] = {1, 10, 3, 8};
    int arr2[] = {12, 2, 9, 6};
    int arr3[] = {5, 7, 4, 11};
    int arr4[] = {3, 7, 16, 5};

    vector<int> vector1(&arr1[0], &arr1[4]);
    vector<int> vector2(&arr2[0], &arr2[4]);
    vector<int> vector3(&arr3[0], &arr3[4]);
    vector<int> vector4(&arr4[0], &arr4[4]);

    vector<vector<int> > vec;

    vec.push_back(vector1);
    vec.push_back(vector2);
    vec.push_back(vector3);
    vec.push_back(vector4);


    Solution sol;

    cout << sol.maxGift(vec) << endl;


    return 0;
}
