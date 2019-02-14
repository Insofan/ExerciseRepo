// 
// @ClassName offer510214
// @Description TODO
// @Date 19-2-14 下午9:24
// @Created by Insomnia
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BSTree{
    int val;
    int count;
    BSTree *left;
    BSTree *right;

    BSTree(int x): val(x), count(0), left(NULL), right(NULL){};
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        vector<int> vec = nums;
        vector<int> res;

        vector<BSTree *> reverseVec;
        for (int i = vec.size() - 1; i >= 0; i--) {
            reverseVec.push_back(new BSTree(vec[i]));
        }
        reverseVec.push_back(NULL);
        res.push_back(0);

        for (int i = 1; i <vec.size(); i++) {
            int small = 0;
            insertBST(reverseVec[0], reverseVec[i], small);
            res.push_back(small);
        }

        int i = 0;
        int j = res.size() - 1;
        reverse(res.begin(), res.end());

        return res;
    }

private:
    void insertBST(BSTree *root, BSTree *node,int &small) {
        if (node->val <= root->val)  {
            root->count++;
            if (root->left) {
                insertBST(root->left, node, small);
            } else {
                root->left= node;
            }
        } else {
            small += root->count + 1;
            if (root->right) {
                insertBST(root->right, node, small);
            } else {
                root->right= node;
            }
        }
    }
};

int main() {
    //1,2,3,4,5,6,7,0
    int arr[] = {1,2,3,4,5,6,7,0};

    vector<int> vec(&arr[0], &arr[8]);

    Solution solution;
    vector<int> res = solution.countSmaller(vec);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    cout << endl;


    return 0;
}
