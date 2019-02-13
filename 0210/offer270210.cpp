//
// @ClassName offer270210
// @Description TODO
// @Date 2019/2/10 8:52 PM
// @Created by Insomnia
//
#include <stdio.h>
#include <iostream>


using namespace std;
struct BinaryTree {
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int x): val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    BinaryTree * mirrorTree(BinaryTree *root) {
        if (!root) {
            return nullptr;
        }

        BinaryTree *tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);

        return root;
    }

};

void preOrder(BinaryTree *node) {
    if (!node) {
        return;
    }

    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int main() {

    BinaryTree a1(1);
    BinaryTree a2(2);
    BinaryTree a3(3);
    BinaryTree a4(4);
    BinaryTree a5(5);
    BinaryTree a6(6);

    a1.left = &a2;
    a1.right = &a3;

    a2.left = &a4;
    a2.right = &a5;

    a3.right = &a6;
    preOrder(&a1);
    cout << endl;

    Solution sol;
    BinaryTree *res = sol.mirrorTree(&a1);

    preOrder(res);
    cout << endl;

    return 0;
}
