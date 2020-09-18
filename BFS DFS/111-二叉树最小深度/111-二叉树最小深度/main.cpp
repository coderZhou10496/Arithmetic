//
//  main.cpp
//  111-二叉树最小深度
//
//  Created by zhoujian on 2020/4/17.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "stack"
#include "queue"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {
        this->val = v;
    }
};

#pragma mark - 基于递归的DFS
int minDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right != nullptr) {
        return minDepth(root->right) + 1;
    }
    if(root->left != nullptr && root->right == nullptr) {
        return minDepth(root->left) + 1;
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

#pragma mark - 基于栈的DFS
int minDepth_DFS(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int res = INT_MAX;
    stack<pair<TreeNode*, int>> s;
    s.push({root, 1});
    while(s.size() > 0) {
        pair<TreeNode*, int> p = s.top();
        s.pop();
        TreeNode *node = p.first;
        int depth = p.second;
        if(node->left == nullptr && node->right == nullptr) {
            res = min(res, depth);
        }
        if(node->left) {
            s.push({node->left, depth+1});
        }
        if(node->right) {
            s.push({node->right, depth+1});
        }
    }
    return  res;
}

#pragma mark - BFS
int minDepth_BFS(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int res = 0;
    queue<TreeNode *>q;
    q.push(root);
    while(q.size() > 0) {
        res++;
        int size = (int)q.size();
        while(size > 0) {
            TreeNode *node= q.front();
            q.pop();
            size--;
            if(node->left == nullptr && node->right == nullptr) {
                return res;
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
