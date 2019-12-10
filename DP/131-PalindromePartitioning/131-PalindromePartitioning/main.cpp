//
//  main.cpp
//  131-PalindromePartitioning
//
//  Created by zhoujian on 2019/12/10.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 
 返回 s 所有可能的分割方案。
 
 示例:
 
 输入: "aab"
 输出:
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/palindrome-partitioning
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
bool isPalindromic(string s) {
    int length = (int)s.size();
    if(length == 0) {
        return false;
    }
    if(length == 1) {
        return true;
    }
    int i = 0;
    int j = length-1;
    while (i <= j) {
        if(s.at(i) != s.at(j)) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void partitionHelper(vector<vector<string>> &res, vector<string> &temp, string s, int index) {
    if(index >= s.size()) {
        res.push_back(temp);
        return;
    }
    for(int i = index; i < s.size(); i++) {
        string cur = s.substr(index, i-index+1);
        if(isPalindromic(cur)) {
            temp.push_back(cur);
            partitionHelper(res, temp, s, i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    partitionHelper(res, temp, s, 0);
    return res;
    
}


int main(int argc, const char * argv[]) {
    vector<vector<string>> res = partition("aab");
    for(auto val : res) {
        for(auto sec : val) {
            cout << sec << " ";
        }
        cout << endl;
    }
    return 0;
}
