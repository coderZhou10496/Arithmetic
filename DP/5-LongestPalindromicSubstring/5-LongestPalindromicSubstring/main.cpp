//
//  main.cpp
//  5-LongestPalindromicSubstring
//
//  Created by zhoujian on 2019/12/10.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 
 示例 1：
 
 输入: "babad"
 输出: "bab"
 注意: "aba" 也是一个有效答案。
 示例 2：
 
 输入: "cbbd"
 输出: "bb"
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
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
// 第一种方法：中心拓展，因为有很多截取字符串的操作，超时
string longestPalindrome(string s) {
    if(s.size() == 0 || s == "") {
        return "";
    }
    string reslutStr;
    
    for(int i = 0; i < s.size(); i++) {
        
        int length = 1;
        int currentIndex = i;
        
        while (currentIndex >= 0 && (currentIndex+length) <= s.size() && isPalindromic(s.substr(currentIndex,length))) {
            string currentStr = s.substr(currentIndex,length);
            if(currentStr.size() > reslutStr.size()) {
                reslutStr = currentStr;
            }
            currentIndex--;
            length += 2;
            
        }
        
        currentIndex = i;
        length = 2;
        while (currentIndex >= 0 && (currentIndex+length) <= s.size() && isPalindromic(s.substr(currentIndex,length))) {
            string currentStr = s.substr(currentIndex,length);
            if(currentStr.size() > reslutStr.size()) {
                reslutStr = currentStr;
            }
            currentIndex--;
            length += 2;
        }
        
    }
    return reslutStr;
}
// 第二种方法：对方法1的优化，也是中心扩展法，可AC
int expandPalindromeLength(string s, int left, int right) {
    int begin = left;
    int end = right;
    while (begin >= 0 && end < s.length() && s.at(begin) == s.at(end)) {
        begin--;
        end++;
    }
    return end-begin-1;
}

string longestPalindrome2(string s) {
    if(s.size() == 0) {
        return "";
    }
    string reslutStr;
    int maxLength = 1;
    int maxStart = 0;
    for(int i = 0; i < s.size(); i++) {
        int length1 = expandPalindromeLength(s, i, i);
        if(length1 > maxLength) {
            maxLength = length1;
            maxStart = i-length1/2;
        }
        
        int length2 = expandPalindromeLength(s, i, i+1);
        if(length2 > maxLength) {
            maxLength = length2;
            maxStart = i - length2/2 + 1;
        }
        
    }
    return s.substr(maxStart, maxLength);
}
// 第三种方法：最长公共子串
/*
 例如，S = "caba"，S' = "abac"，最长公共子串是 "aba"，所以原字符串的最长回文串就是 "aba"。
 */

string sameString(string s1, string s2) {
    
    vector<vector<int>> array(s1.length(), vector<int>(s2.length()));
    
    int l1 = (int)s1.length();
    int l2 = (int)s2.length();
    for(int i = 0; i < l2; i++) {
        bool equal = s1.substr(i,1).compare(s2.substr(0,1));
        array[0][i] = equal ? 0 : 1;
    }
    for(int j = 0; j < l1; j++) {
        bool equal = s2.substr(j,1).compare(s1.substr(0,1));
        array[j][0] = equal ? 0 : 1;
    }
    int result = 1;
    int maxEnd = 0;
    for(int i = 1; i < l1; i++) {
        for(int j = 1; j < l2; j++) {
            if(s1.substr(j,1).compare(s2.substr(i,1)) == false) { // 字符串比较 相等输出false
                int current = array[i-1][j-1] + 1;
                array[i][j] = current;
                if(current > result) {
                    
                    if(isPalindromic(s1.substr(j+1-current,current))) { // 这里还要判断一下
                        result = current;
                        maxEnd = j;
                    }

                }
            }
            else {
                array[i][j] = 0;
            }
        }
    }
    
    return s1.substr(maxEnd - result + 1, result);
}
string longestPalindrome3(string s) {
    if(s.size() == 0 || s == "") {
        return "";
    }
    string reverseStr = s;
    reverse(reverseStr.begin(), reverseStr.end());
    
    return sameString(s, reverseStr);

}
int main(int argc, const char * argv[]) {
    string s = "caba";
    string res = longestPalindrome3(s);
    cout << res << endl;

    
//    string s1 = "abbbd";
//    string s3 = s1;
//    string s2 = "abbvd";
//    reverse(s1.begin(), s1.end());
//
//    string res = sameString(s1, s2);
//    cout << res << endl;
    return 0;
}
