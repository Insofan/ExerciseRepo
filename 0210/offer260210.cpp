//
// @ClassName offer260210
// @Description TODO
// @Date 2019/2/10 8:40 PM
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
    bool isSubTree(BinaryTree *root, BinaryTree*node) {

        if (isSameTree(root, node)) {
            return true;
        }

        return isSameTree(root->left, node) || isSameTree(root->right, node);
    }

private:
    bool isSameTree(BinaryTree *node1, BinaryTree *node2) {
        if (!node1 || !node2) {
            return node1 == node2;
        } else {
            return (node1->val == node2->val) && isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
        }
    }
};


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

    BinaryTree b1(1);
    BinaryTree b2(2);
    BinaryTree b3(3);


    b1.left  = &b2;
    b1.right = &b3;

    Solution sol;

    cout << boolalpha << sol.isSubTree(&a1, &a3) << endl;
    cout << boolalpha << sol.isSubTree(&a1, &a2) << endl;
    cout << boolalpha << sol.isSubTree(&a1, &b1) << endl;

    return 0;
}
