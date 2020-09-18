//
//  main.cpp
//  104-二叉树最大深度
//
//  Created by zhoujian on 2020/4/18.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "queue"
#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
    }
};
#pragma mark - 基于递归的DFS
int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

#pragma mark - 基于栈的DFS
int maxDepth_DFS(TreeNode* root) {
    if(!root)return 0;
    
    stack<pair<TreeNode*,int>>s;
    TreeNode* p = root;
    int MaxDeep = 0;
    int Deep = 0;
    while(!s.empty() || p)
    {
        while(p)
        {
            s.push(pair<TreeNode*,int>(p,Deep+1));
            Deep++;
            p = p->left;
        }
        p = s.top().first;
        Deep = s.top().second;
        s.pop();
        MaxDeep = max(MaxDeep, Deep);
        p = p->right;
    }
    return MaxDeep;
    
}

#pragma mark - BFS
int maxDepth_BFS(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int res = 0;
    while(q.size() > 0) {
        int size = (int)q.size();
        while(size > 0) {
            TreeNode *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            size--;
        }
        res++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
