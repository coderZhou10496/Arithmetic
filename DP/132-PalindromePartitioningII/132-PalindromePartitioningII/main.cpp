//
//  main.cpp
//  132-PalindromePartitioningII
//
//  Created by zhoujian on 2019/12/11.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 
 返回符合要求的最少分割次数。
 
 示例:
 
 输入: "aab"
 输出: 1
 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 方法1：很优秀的解法
int minCut(string s) {

    int length = (int)s.size();
    if(length == 0 || length == 1) {
        return 0;
    }
    
    vector<int> v; // 长度为 i 的字符串，最多切 i - 1 次，都变成单个字符，就是回文串了
    for(int i = 0; i < length+1; i++) {
        v.push_back(i-1);
    }
    
    for(int i = 0; i < length; i++) {
        
        v[i+1] = min(v[i+1],v[i]+1);
        
        int start = i;
        int end = i+1;
        while(start >= 0 && end < length && s[start] == s[end]) {
            
            v[end+1] = min(v[end+1], v[start]+1);
            start--;
            end++;
            
        }
        
        start = i-1;
        end = i+1;
        while(start >= 0 && end < length && s[start] == s[end]) {
            v[end+1] = min(v[end+1], v[start]+1);
            start--;
            end++;
        }
        if(v[length] == 0){
            return 0;
        }
    }
    return v[length];

}

// 方法2：虽然能AC,但占用了大量内存及时间，不推荐使用
bool isPalindromic(string s, int left, int right) {
    if(left < 0 || right >= s.size()) {
        return false;
    }
    while (left < right ) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int minCut2(string s) {
    int length = (int)s.size();
    if(length == 0 || length == 1) {
        return 0;
    }
    
    vector<int> v; // 长度为 i 的字符串，最多切 i - 1 次，都变成单个字符，就是回文串了
    for(int i = 0; i < length+1; i++) {
        v.push_back(i-1);
    }
    for(int i = 1; i <= length; i++) {
        for(int j = 0; j < i; j++) {
            if(isPalindromic(s, j, i-1)) {
                v[i] = min(v[i],v[j]+1);
            }
        }
    }
    return v[length];
}
int main(int argc, const char * argv[]) {

    string s = "cbbbbc";
    cout << minCut2(s) << endl;

    return 0;
}
