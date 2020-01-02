//
//  main.cpp
//  32-LongestValidParentheses
//
//  Created by zhoujian on 2020/1/2.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

/*
 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 
 示例 1:
 
 输入: "(()"
 输出: 2
 解释: 最长有效括号子串为 "()"
 示例 2:
 
 输入: ")()())"
 输出: 4
 解释: 最长有效括号子串为 "()()"
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 解法一：DP
int longestValidParentheses(string s) {
    
    int length = (int)s.size();
    if(length == 0 || length == 1) {
        return 0;
    }
    int res = 0;
    // dp[i] 表示到第i个字符时，当前能组成有效括号的长度
    vector<int> dp(length,0);

    for(int i = 1; i < length; i++) {
        char current = s[i];
        char last = s[i-1];
        if(current == '(') {
            // ...(
            dp[i] = 0;
        }
        else {
            if(last == '(') {
                // ()
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else {
                // ))
                if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') { // ((()))
                    dp[i] = dp[i-1] + 2 + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                }
            }
        }
        res = max(dp[i], res);
    }
    
    return res;
}
// 解法二：使用栈
int longestValidParentheses_solution2(string s) {
    int length = (int)s.size();
    if(length == 0 || length == 1) {
        return 0;
    }
    int res = 0;
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < length; i++) {
        char current = s[i];
        if(current == '(') {
            st.push(i);
        }
        else {
            st.pop();
            if(st.empty()) {
                st.push(i);
            }
            else {
                res = max(res, i-st.top());
            }
        }
    }
    return res;
}

// 解法三：很神奇的解法
/*
 
 从左到右扫描，用两个变量 left 和 right 保存的当前的左括号和右括号的个数，都初始化为 0 。
 
 如果左括号个数等于右括号个数了，那么就更新合法序列的最长长度。
 如果左括号个数大于右括号个数了，那么就接着向右边扫描。
 如果左括号数目小于右括号个数了，那么后边无论是什么，此时都不可能是合法序列了，此时 left 和 right 归 0，然后接着扫描。
 从左到右扫描完毕后，同样的方法从右到左再来一次，因为类似这样的情况 ( ( ( ) ) ，如果从左到右扫描到最后，left = 3，right = 2，期间不会出现 left == right。但是如果从右向左扫描，扫描到倒数第二个位置的时候，就会出现 left = 2，right = 2 ，就会得到一种合法序列。
 
 */
int longestValidParentheses_solution3(string s) {
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * right);
        } else if (right >= left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * left);
        } else if (left >= right) {
            left = right = 0;
        }
    }
    return maxlength;

}
int main(int argc, const char * argv[]) {
    string s = "(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(";
    int res = longestValidParentheses(s);
    cout << res << endl;
    return 0;
}
