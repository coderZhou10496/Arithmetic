//
//  main.cpp
//  221-MaximalSquare
//
//  Created by zhoujian on 2020/1/15.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 
 示例:
 
 输入:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 
 输出: 4
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximal-square
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int maximalSquare(vector<vector<int>> &matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    int res = 0 ;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
            }
            else if(matrix[i][j] == 1) {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res*res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 1, 1},
    };
    int res = maximalSquare(matrix);
    cout << res << endl;
    return 0;
}
