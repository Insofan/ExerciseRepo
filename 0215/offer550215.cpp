//
// @ClassName offer550215
// @Description TODO
// @Date 2019/2/15 2:27 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>


struct BinaryTree {
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int x): val(x), left(NULL), right(NULL){};
};

using namespace std;

class Solution {
public:
    int depthOfTree(BinaryTree *root) {
        if (!root) {
            return 0;
        } else {
            return 1 + max(depthOfTree(root->left), depthOfTree(root->right));
        }
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
    
    cout << sol.depthOfTree(&a1) << endl;
    return 0;
}
