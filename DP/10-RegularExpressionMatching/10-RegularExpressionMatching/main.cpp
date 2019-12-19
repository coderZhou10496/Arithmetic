//
//  main.cpp
//  10-RegularExpressionMatching
//
//  Created by zhoujian on 2019/12/19.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 
 '.' 匹配任意单个字符
 '*' 匹配零个或多个前面的那一个元素
 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 
 说明:
 
 s 可能为空，且只包含从 a-z 的小写字母。
 p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 示例 1:
 
 输入:
 s = "aa"
 p = "a"
 输出: false
 解释: "a" 无法匹配 "aa" 整个字符串。
 示例 2:
 
 输入:
 s = "aa"
 p = "a*"
 输出: true
 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 示例 3:
 
 输入:
 s = "ab"
 p = ".*"
 输出: true
 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 示例 4:
 
 输入:
 s = "aab"
 p = "c*a*b"
 输出: true
 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 示例 5:
 
 输入:
 s = "mississippi"
 p = "mis*is*p*."
 输出: false
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/regular-expression-matching
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */


bool isMatch(string s, string p) {
    
    int sLength = (int)s.size();
    int pLength = (int)p.size();

    vector<vector<bool>> dp(sLength+1, vector<bool>(pLength+1));
    dp[0][0] = true;
    
    // 初始化边界条件，处理这种情况 s = "", p = ".*.*"
    for(int i = 0; i < pLength; i++) {
        if(p[i] == '*' && dp[0][i-1] == true) {
            dp[0][i+1] = true;
        }
        else {
            dp[0][i+1] = false;
        }
    }
    // dp[i][j]：s的前i个能否被p的前j个匹配
    for(int i = 1; i <= sLength; i++) {
        for(int j = 1; j <= pLength; j++) {
            
            if(p[j-1] == s[i-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if (p[j-1] == '*') {
                if(s[i-1] != p[j-2]) {
                    
                    // abc abd*
                    dp[i][j] = dp[i][j-2];
                }
                if(s[i-1] == p[j-2] || p[j-2] == '.') {
                    
                    /*
                     dp[i][j] = dp[i][j-1]: ab ab*
                     dp[i][j] = dp[i][j-2]:  ab abb*
                     dp[i][j] = dp[i-1][j]:  abbbb ab*
                     */
                    
                    dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                }

            }
        }
    }
    return dp[sLength][pLength];

}

int main(int argc, const char * argv[]) {
    cout << isMatch("", ".*.*.*") << endl;
//    cout << isMatch("aa", "a*") << endl;
//    cout << isMatch("ab", ".*") << endl;
//    cout << isMatch("aab", "c*a*b") << endl;
//    cout << isMatch("ssippi", "s*p*.") << endl;
//    cout << isMatch("aa", "b*a*c*a") << endl;
//    cout << isMatch("ab", ".*c") << endl;
    return 0;
}
