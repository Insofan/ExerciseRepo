//
// @ClassName offer280210
// @Description TODO
// @Date 2019/2/10 9:00 PM
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
    bool isSymmetric(BinaryTree *root) {
        if (!root) {
            return true;
        }

        BinaryTree *tmp = mirrorTree(root->left);
        if (isSameTree(tmp, root->right)) {
            return true;
        }

        return false;
    }

private:
    BinaryTree *mirrorTree(BinaryTree *root) {
        if (!root) {
            return nullptr;
        }

        BinaryTree *tmp = root->left;
        root->left  = mirrorTree(root->right);
        root->right = mirrorTree(tmp);

        return root;
    }

    bool isSameTree(BinaryTree *node1, BinaryTree *node2) {
        if (!node1 || !node2) {
            return node1 == node2;
        } else {
            return node1->val == node2->val && isSameTree(node1->left, node2->left) &&
                   isSameTree(node1->right, node2->right);
        }
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

    a1.left  = &a2;
    a1.right = &a3;

    a2.left  = &a4;
    a2.right = &a5;

    a3.right        = &a6;
    preOrder(&a1);
    cout << endl;

    Solution   sol;
    bool res = sol.isSymmetric(&a1);


    return 0;
}
