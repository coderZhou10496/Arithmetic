//
//  main.cpp
//  62-UniquePaths
//
//  Created by zhoujian on 2019/11/29.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 
 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 
 问总共有多少条不同的路径？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/unique-paths
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
void cusPrintf(vector<vector<int>>& res) {
    for(auto val:res) {
        for(auto val2:val) {
            cout << val2 << " ";
        }
        cout << endl;
    }
}
int uniquePaths(int m, int n) {
    
    if(m == 0 && n == 0) {
        return 0;
    }
    
    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        res[i][0] = 1;
        for(int j = 0; j < m; j++) {
            res[0][j] = 1;
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            res[i][j] = res[i][j-1] + res[i-1][j];
        }
    }
    
    return res[n-1][m-1];
}



int main(int argc, const char * argv[]) {
    int res = uniquePaths(7, 3);
    cout << "res:" << res << endl;
    return 0;
}
