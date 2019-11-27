//
//  main.cpp
//  54-SpiralMatrix
//
//  Created by zhoujian on 2019/11/27.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 
 示例 1:
 
 输入:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 输出: [1,2,3,6,9,8,7,4,5]
 示例 2:
 
 输入:
 [
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
 ]
 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/spiral-matrix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    vector<int> res;
    if(matrix.size() == 0) {
        return res;
    }
    
    int top = 0;
    int right = (int)matrix[0].size()-1;
    int bottom = (int)matrix.size()-1;
    int left = 0;
    
    while(top <= bottom || left <= right) {
        
        for(int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
        }
        top++;
        if(top > bottom) {
            break;
        }

        for(int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;
        if(left > right) {
            break;
        }

        for(int i = right; i >= left; i--) {
            res.push_back(matrix[bottom][i]);
        }
        bottom--;
        if(top > bottom) {
            break;
        }

        for(int i = bottom; i>= top; i--) {
            res.push_back(matrix[i][left]);
        }
        left++;
        if(left > right) {
            break;
        }
        
    }
    
    return res;
}

int main(int argc, const char * argv[]) {

    vector<vector<int>> num1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<vector<int>> num2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
    };
    vector<int> res1 = spiralOrder(num1);
    vector<int> res2 = spiralOrder(num2);
    for(auto val : res1) {
        cout << val << " ";
    }
    cout << endl;
    
    for(auto val : res2) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
