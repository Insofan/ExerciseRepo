// 
// @ClassName offer320212
// @Description TODO
// @Date 19-2-12 下午4:09
// @Created by Insomnia
//

#include <vector>
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

    vector<vector<int> > layerOrder(BinaryTree *root) {
        vector<vector<int> > res;
        layerHelper(root, 0, res);
        return res;
    }

private:
    void layerHelper(BinaryTree *node, int layer, vector<vector<int> > &res) {
        if (!node) {
            return;
        }
        if (layer == res.size()) {
            res.push_back(vector<int>());
        }

        res[layer].push_back(node->val);
        layerHelper(node->left, layer + 1, res);
        layerHelper(node->right, layer + 1, res);
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

    Solution sol;
    vector<vector<int> > res = sol.layerOrder(&a1);

            for (int i = 0; i < res.size(); i++) {
                cout << "layer " << i << " : ";
                for (int j = 0; j < res[i].size(); j++) {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }

    return 0;
}