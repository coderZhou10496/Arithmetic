//
//  main.cpp
//  474-OnesandZeroes
//
//  Created by zhoujian on 2019/12/29.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "string"
#include "vector"
using namespace std;

/*
 在计算机界中，我们总是追求用有限的资源获取最大的收益。
 
 现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
 
 你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
 
 注意:
 
 给定 0 和 1 的数量都不会超过 100。
 给定字符串数组的长度不会超过 600。
 示例 1:
 
 输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 输出: 4
 
 解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
 示例 2:
 
 输入: Array = {"10", "0", "1"}, m = 1, n = 1
 输出: 2
 
 解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1"
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ones-and-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
// m个0， n个1
int findMaxForm(vector<string>& strs, int m, int n) {
    int length = (int)strs.size();
    if(length == 0) {
        return 0;
    }
    
    /*
     dp[m][n] 表示m个0，n个1能拼接出存在于数组中的字符串的最大数量
     */
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    dp[0][0] = 0;

    
    for(string str : strs) {
        int zeroNum = 0;
        int oneNum = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '1') {
                oneNum++;
            }
            else {
                zeroNum++;
            }
        }
        
        for(int i = m; i >= zeroNum; i--) {
            for(int j = n; j >= oneNum; j--) {
                dp[i][j] = max(dp[i][j], 1 + dp[i-zeroNum][j-oneNum]);
            }
        }
        
    }
    return dp[m][n];
}


int main(int argc, const char * argv[]) {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int res = findMaxForm(strs, 5, 3);
    cout << res << endl;
    return 0;
}
