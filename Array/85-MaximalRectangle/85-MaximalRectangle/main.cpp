//
//  main.cpp
//  85-MaximalRectangle
//
//  Created by zhoujian on 2019/12/7.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

/*
 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 
 示例:
 
 输入:
 [
 ["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]
 ]
 输出: 6
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximal-rectangle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

int maxArea(vector<int> &v) {
    
    int res = 0;
    
    stack<int> s;
    v.push_back(0);
    
    for(int i = 0; i < v.size(); i++) {
        while (!s.empty() && v[i] <= v[s.top()]) {
            int topValue = s.top();
            s.pop();
            res = max(res, v[topValue] * (s.empty() ? i : i-s.top()-1));
        }
        s.push(i);
    }
    return res;
}

// 类似于84题
int maximalRectangle(vector<vector<char>>& matrix) {
    int row = (int)matrix.size();
    if(row == 0) {
        return 0;
    }
    int column = (int)matrix[0].size();
    if(column == 0) {
        return 0;
    }
    
    vector<vector<int>> v(row, vector<int>(column, 0));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            int temp = i;
            int value = 0;
            while (temp >= 0 && matrix[temp][j] == '1') {
                    value++;
                    temp--;
            }
            v[i][j] = value;
        }
    }
    for(auto val : v) {
        for(auto sec : val) {
            cout << sec << " ";
        }
        cout << endl;
    }
    
    int result = 0;
    for(int i = 0; i < v.size(); i++) {
        result = max(result, maxArea(v[i]));
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> matrix = {
        
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    int res = maximalRectangle(matrix);
    cout << res << endl;
    return 0;
}
