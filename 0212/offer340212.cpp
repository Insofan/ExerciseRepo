// 
// @ClassName offer340212
// @Description TODO
// @Date 19-2-12 下午4:22
// @Created by Insomnia
//

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTree {
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int x): val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    vector<vector<int> > sumPath(BinaryTree *root, int tar) {
        if (!root) {
            return vector<vector<int> >();
        }

        vector<vector<int> > res;
        vector<int> pathVec;
        int pathSum = 0;
        helper(root, res, pathVec, tar, pathSum);
        return res;

    }

private:
    void helper(BinaryTree *node, vector<vector<int> > &res, vector<int> &pathVec, int tar, int &pathSum) {
        if (!node) {
            return;
        }

        pathSum += node->val;
        pathVec.push_back(node->val);

        if ( pathSum == tar) {
            res.push_back(pathVec);
        }

        helper(node->left, res, pathVec, tar, pathSum);
        helper(node->right, res, pathVec, tar, pathSum);
        pathSum -= node->val;
        pathVec.pop_back();
    }

};

int main() {
    BinaryTree a1(10);
    BinaryTree a2(5);
    BinaryTree a3(12);
    BinaryTree a4(4);
    BinaryTree a5(7);

    a1.left = &a2;
    a1.right = &a3;

    a2.left = &a4;
    a2.right = &a5;

    Solution sol;
    vector<vector<int> > res = sol.sumPath(&a1, 22);
   // cout << res.size() << endl;
           for (int i = 0; i < res.size(); i++) {
               for (int j = 0; j < res[i].size(); j++) {
                   cout << res[i][j] << " ";
               }
               cout << endl;
           }

    return 0;
}