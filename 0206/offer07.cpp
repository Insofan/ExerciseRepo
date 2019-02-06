//
// @ClassName offer07
// @Description TODO
// @Date 2019/2/6 9:55 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

struct  BinaryTree {

    int val;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:

    string serBt(BinaryTree *root) {

        ostringstream out;
        serHelpr(out, root);
        return out.str();
    }

    BinaryTree *deserBt(string str) {

        istringstream in(str);

        return deserHelper(in);
    }

private:
    void serHelpr(ostringstream &out, BinaryTree *node) {
        if (!node) {
            out << "# ";
            return;
        }

        out << node->val << " ";
        serHelpr(out, node->left);
        serHelpr(out, node->right);
    }

   BinaryTree *deserHelper(istringstream &in) {
        string str;
        in >> str;
        if (str == "#") {
            return NULL;
        }

        BinaryTree *res = new BinaryTree(stoi(str));
        res->left = deserHelper(in);
       res->right = deserHelper(in);

       return res;
    }

};

void layerOrder(BinaryTree *root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";

    layerOrder(root->left);
    layerOrder(root->right);
//    cout << endl;
}



int main() {

//    string str = "1 2 # # 3 # # 4 # # 5 # #";
    BinaryTree a1(1);
    BinaryTree a2(2);
    BinaryTree a3(3);
    BinaryTree a4(4);
    BinaryTree a5(5);
    a1.left = &a2;
    a1.right = &a4;


    a2.right = &a3;

    a4.left = &a5;

    Solution sol;

//    string res = sol.serBt(&a1);
//    cout << res << endl;


    BinaryTree *root = sol.deserBt(sol.serBt(&a1));

    layerOrder(root);


    return 0;
}
