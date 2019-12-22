//
//  main.cpp
//  140-WordBreakII
//
//  Created by zhoujian on 2019/12/20.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "set"
using namespace std;

/*
 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 
 说明：
 
 分隔时可以重复使用字典中的单词。
 你可以假设字典中没有重复的单词。
 示例 1：
 
 输入:
 s = "catsanddog"
 wordDict = ["cat", "cats", "and", "sand", "dog"]
 输出:
 [
   "cats and dog",
   "cat sand dog"
 ]
 示例 2：
 
 输入:
 s = "pineapplepenapple"
 wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 输出:
 [
   "pine apple pen apple",
   "pineapple pen apple",
   "pine applepen apple"
 ]
 解释: 注意你可以重复使用字典中的单词。
 示例 3：
 
 输入:
 s = "catsandog"
 wordDict = ["cats", "dog", "sand", "and", "cat"]
 输出:
 []
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/word-break-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */



vector<string> wordBreak(string s, vector<string>& wordDict) {
    
    int length = (int)s.length();
    
    /*
     在139题中，dp为一维数组，dp[i]表示前i个字符串是否可以匹配，bool值
     但在此题中,如果前i个字符可以匹配，还要记录每次匹配的字符串，比如：
     s = "catsanddog"
     wordDict = ["cat", "cats", "and", "sand", "dog"]
     s中前7个字符catsand可以匹配，但是有两种方式匹配，cat，sand 和 cats，sand.
     所以每次匹配时要记录这个一次匹配串的长度。
     dp[0] = {0};
     dp[3] = {3}; // 当i=3时，前3个可以匹配，记录此时可以匹配的字符串长度3
     dp[4] = {4}; // 当i=4时，前4个可以匹配，记录此时可以匹配的字符串长度7
     dp[7] = {3,4}; // 当i=7时，前3个字符and可以匹配，记录为3；前4个字符sand也可以匹配,记录为4
     dp[10] = {3};
     */
    
    vector<vector<int>> dp(length+1);
    dp[0] = {0};
    
    for(int i = 0; i <= s.size(); i++) {
        for(auto word : wordDict) {
            int wordLength = (int)word.size();
            if(i >= wordLength) {
                string subStr = s.substr(i-wordLength, wordLength);
                if(subStr == word && !dp[i-wordLength].empty()) {
                    dp[i].push_back(wordLength);
                }
            }
        }
    }
    

    if(dp[length].empty()) {
        return vector<string>(); // 剪枝：整个串都不匹配，直接返回
    }
    
    vector<vector<string>> res(length+1); // res[i] 表示前i个字符串匹配时，所有的匹配方式
    
    /*
     上面已经找到了每次匹配的的字符长度，现在可以求结果了
     */
    for(int i = 1; i <= s.size(); i++) {
        if(dp[i].empty()) {
            continue;
        }
        vector<int> lengthArr = dp[i];
        for(auto autoLength : lengthArr) { //autoLength表示这一次匹配的匹配长度
            if(dp[i-autoLength][0] == 0) {
                res[i].push_back(s.substr(i-autoLength,autoLength)); // 这里说明是第一次匹配成功，跟之前的没有关联
            }
            else {
                /*
                 更新元素：res[i-autoLength]中的每一个元素都要更新，更新后的结果即为res[i]
                 */
                for(auto str : res[i-autoLength]) {
                    res[i].push_back(str + ' ' + s.substr(i-autoLength,autoLength));
                }
            }
        }
    }
    return res[length];
}

int main(int argc, const char * argv[]) {
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = wordBreak("catsanddog", wordDict);
    
    
//    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
//    vector<string> res = wordBreak("pineapplepenapple", wordDict);
    
    cout << "----" << endl;
    for(auto str : res) {
        cout << str << endl;
    }
    return 0;
}
