// 
// @ClassName MinTree0225
// @Description TODO
// @Date 19-2-25 下午9:28
// @Created by Insomnia
//

#include <iostream>

struct BSTree{
    int val;
    BSTree *left;
    BSTree *right;

    BSTree(int x): val(x), left(NULL), right(NULL){};
};

using namespace std;

class Solution {
public:

    int minDepthTree(BSTree *root) {
        if (!root) {
            return 0;
        }

        if (!root->left) {
            return  1 + minDepthTree(root->right);
        }

        if (!root->right) {
            return 1 + minDepthTree(root->left);
        }

        int ld = minDepthTree(root->left);
        int rd = minDepthTree(root->right);

        return 1 + min(ld, rd);
    }

};


int main() {
    BSTree a1(10);
    BSTree a2(5);
    BSTree a3(12);
    BSTree a4(4);
    BSTree a5(7);

    a1.left = &a2;
    a1.right = &a3;

    a2.left = &a4;
    a2.right = &a5;

    Solution sol;

    cout << sol.minDepthTree(&a1) << endl;
    return 0;
}