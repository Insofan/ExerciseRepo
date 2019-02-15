//
// @ClassName offer540215
// @Description TODO
// @Date 2019/2/15 2:20 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>


struct BSTree{
    int val;
    BSTree *left;
    BSTree *right;

    BSTree(int x): val(x), left(NULL), right(NULL){};
};

using namespace std;

class Solution {
public:
    BSTree * kthInBST(BSTree *root, int k) {
        vector<BSTree *> res;

        generate(root, res);

        return res[k - 1];
    }


private:

    void generate(BSTree *node, vector<BSTree *> &vec) {
        if (!node) {
            return;
        }

        generate(node->left, vec);
        vec.push_back(node);
        generate(node->right, vec);

    }

};


int main() {

    return 0;
}
