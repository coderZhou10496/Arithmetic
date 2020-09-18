//
//  main.cpp
//  139-WordBreak
//
//  Created by zhoujian on 2019/12/18.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 
 说明：
 
 拆分时可以重复使用字典中的单词。
 你可以假设字典中没有重复的单词。
 示例 1：
 
 输入: s = "leetcode", wordDict = ["leet", "code"]
 输出: true
 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 示例 2：
 
 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 输出: true
 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
      注意你可以重复使用字典中的单词。
 示例 3：
 
 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 输出: false
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/word-break
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

bool wordBreak(string s, vector<string>& wordDict) {
    
    if(s.size() == 0 || wordDict.size() == 0) {
        return false;
    }
    
    
//    遍历wordDict中的word，与s的字串（从i开始，往前数word.size()个）进行比较，如果比较结果一致，则查看dp。
//    i处dp[i]设置为1的条件是：从i往前数word.size()个，再往前数1个，如果该处dp也为1,则设置dp[i]=1
    
    
    vector<int> dp(s.size()+1);
    dp[0] = 1;
    
    for(int i = 0; i <= s.size(); i++) {
        
        for(auto word : wordDict) {
            
            int wordLength = (int)word.size();
            if(i >= wordLength) {
                string subStr = s.substr(i-wordLength, wordLength);
                if(subStr == word && dp[i-wordLength] == 1) {
                    dp[i] = 1;
                }
            }
        }
    }
    return dp[s.size()];
    
    // 下面的这种DP也可以，速度稍慢
//    vector<bool> dp(s.size() + 1);
//    dp[0] = true;
//    for (int i = 1; i <= s.size(); i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
//            {
//                dp[i] = true;
//                break;
//            }
//        }
//    }
//    return dp[s.size()];
}

int main(int argc, const char * argv[]) {

    string s = "dogs";
    vector<string> wordDict = {"dog","s","gs"};
    
//    string s = "aaaaaaa";
//    vector<string> wordDict = {"aaaa","aaa"};
    
//    string s = "leetcode";
//    vector<string> wordDict = {"leet", "code"};
    
//    string s = "a";
//    vector<string> wordDict = {"a"};
    
    bool res = wordBreak(s, wordDict);
    cout << res << endl;
    return 0;
}
