//
//  main.cpp
//  72-EditDistance
//
//  Created by zhoujian on 2020/1/8.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 
 你可以对一个单词进行如下三种操作：
 
 插入一个字符
 删除一个字符
 替换一个字符
 示例 1:
 
 输入: word1 = "horse", word2 = "ros"
 输出: 3
 解释:
 horse -> rorse (将 'h' 替换为 'r')
 rorse -> rose (删除 'r')
 rose -> ros (删除 'e')
 示例 2:
 
 输入: word1 = "intention", word2 = "execution"
 输出: 5
 解释:
 intention -> inention (删除 't')
 inention -> enention (将 'i' 替换为 'e')
 enention -> exention (将 'n' 替换为 'x')
 exention -> exection (将 'n' 替换为 'c')
 exection -> execution (插入 'u')
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/edit-distance
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */



int minDistance(string word1, string word2) {
    
    int length1 = (int)word1.length();
    int length2 = (int)word2.length();
    
    // dp[i][j] word1的前i位，匹配word2的前j位所需要的最少次数
    
    /*
     如果 s1[i] == s2[j], dp[i][j] = dp[i-1][j-1];
     如果 s1[i] != s2[j],
     直接对s1[i]进行转换，dp[i][j] = dp[i-1][j-1] + 1;
     s1插入一个字符，dp[i][j] = dp[i][j-1]+1;
     s1删除一个字符，dp[i][j] = dp[i-1][j]+1;
     */
    vector<vector<int>> dp(length1+1, vector<int>(length2+1,0));
    for(int i = 1; i <= length1; i++) {
        dp[i][0] = i;
    }
    for(int j = 1; j <= length2; j++) {
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= length1; i++) {
        for(int j = 1; j <= length2; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(min(dp[i][j-1]+1, // s1插入一个字符
                               dp[i-1][j]+1), // s1删除一个字符
                               dp[i-1][j-1]+1); // s1替换一个字符
            }
        }
    }
    return dp[length1][length2];
    
    /*
    对“dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作。”的补充理解：
    
    以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，因此有：
    
    (1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 2 个字符 ro，然后将第五个字符 word1[4]（因为下标基数以 0 开始） 由 e 替换为 s（即替换为 word2 的第三个字符，word2[2]）
    
    (2) dp[i][j-1]，即先将 word1 的前 5 个字符 horse 转换为 word2 的前 2 个字符 ro，然后在末尾补充一个 s，即插入操作
    
    (3) dp[i-1][j]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 3 个字符 ros，然后删除 word1 的第 5 个字符
     */
}


int main(int argc, const char * argv[]) {
    
    int res = minDistance("horse", "ros");
    cout << res << endl;
    
    return 0;
}
