//
// @ClassName offer08
// @Description TODO
// @Date 2019/2/8 5:47 PM
// @Created by Insomnia
//

/*
 * 给定一棵二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？树中的节点除了有两个分别别指向左右子节点的指针，还有一个指向父节点的指针
 */

#include <stdio.h>
#include <iostream>

using namespace std;

struct PBinaryTree {
    int val;
    PBinaryTree *left;
    PBinaryTree *right;
    PBinaryTree *parent;
};

class Solution {
public:

    PBinaryTree *nextNode(PBinaryTree *root) {


        return NULL;
    }


};


int main() {

    return 0;
}
