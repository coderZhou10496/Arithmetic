//
//  main.cpp
//  87-ScrambleString
//
//  Created by zhoujian on 2020/1/9.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
 
 下图是字符串 s1 = "great" 的一种可能的表示形式。
 
     great
    /    \
   gr    eat
  / \   /  \
  g   r  e   at
 / \
 a   t
 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
 
 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
 
      rgeat
     /    \
    rg    eat
   / \    /  \
  r   g  e   at
 / \
 a   t
 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
 
 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。
 
     rgtae
     /    \
    rg    tae
   / \    /  \
  r   g  ta  e
 / \
 t   a
 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
 
 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
 
 示例 1:
 
 输入: s1 = "great", s2 = "rgeat"
 输出: true
 示例 2:
 
 输入: s1 = "abcde", s2 = "caebd"
 输出: false

 */

// 方法1：暴力递归
bool isScramble(string s1, string s2) {
    
    int length1 = (int)s1.size();
    int length2 = (int)s2.size();
    if(length1 != length2) {
        return false;
    }
    if(s1 == s2) {
        return true;
    }
    // 如果两个字符串中，每个字母出现的次数不一致，为false
    vector<int> charNumber(26,0);
    for(int i = 0; i < length1; i++) {
        charNumber[s1[i] - 'a']++;
        charNumber[s2[i] - 'a']--;
    }
    for(int num : charNumber) {
        if(num != 0) {
            return false;
        }
    }
    
    for(int i = 1; i < length1; i++) {
        // s1的前i和字符和s2的前i个字符匹配
        if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,length1-i), s2.substr(i,length1-i))) {
            return true;
        }
        // s1的前i和字符和s2的后i个字符匹配
        if(isScramble(s1.substr(0,i), s2.substr(length1-i,i)) && isScramble(s1.substr(i,length1-i), s2.substr(0,length1-i))) {
            return true;
        }
    }
    return false;
}

// 方法二：DP(leetcode上很少有人用dp来解，虽然这道题的标签是dp,不过这道题递归效率确实比dp好)
bool isScramble_solution2(string s1, string s2) {
    int length1 = (int)s1.size();
    int length2 = (int)s2.size();
    if(length1 != length2) {
        return false;
    }
    if(s1 == s2) {
        return true;
    }
    // 如果两个字符串中，每个字母出现的次数不一致，为false
    vector<int> charNumber(26,0);
    for(int i = 0; i < length1; i++) {
        charNumber[s1[i] - 'a']++;
        charNumber[s2[i] - 'a']--;
    }
    for(int num : charNumber) {
        if(num != 0) {
            return false;
        }
    }

    /*
     dp[i][j][k] 表示 s1从i开始后的k个字符 能否转换为s2从j开始的k个字符
     转移方程为：dp[i][j][len] = (dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k])
     dp[i][j][k] && dp[i+k][j+k][len-k]  表示s1的前半部分和s2的前半部分匹配，并且s1的后半部分和s2的后半部分匹配
     dp[i][j+len-k][k] && dp[i+k][j][len-k]  表示s1的前半部分和s2的后半部分匹配，并且s1的后半部分和s2的前半部分匹配
     */
    vector<vector<vector<bool>>> dp(length1, vector<vector<bool>>(length2, vector<bool>(length1+1, false)));
    for(int len = 1; len <= length1; len++) { // 遍历所有字符串长度
        for(int i = 0; i+len <= length1; i++) { // s1开始的地方
            for(int j = 0; j+len <= length2; j++) { // s2开始的地方
                if(len == 1) { // 如果长度是1，只需要判断两者是否相等
                    dp[i][j][1] = (s1[i] == s2[j]);
                }
                else {
                    for(int k = 1; k < len; k++) { // k为切割后左半部分长度
                        dp[i][j][len] = (dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                        if(dp[i][j][len]) {
                            break;
                        }
                    }
                }
            }
        }
    }
    return dp[0][0][length1];
    
}
int main(int argc, const char * argv[]) {
    cout << isScramble_solution2("great", "rgeat") << endl;
    cout << isScramble_solution2("abc", "bca") << endl;
    return 0;
}

