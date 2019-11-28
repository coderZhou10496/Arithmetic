//
//  main.cpp
//  59-SpiralMatrixII
//
//  Created by zhoujian on 2019/11/28.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 
 示例:
 
 输入: 3
 输出:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/spiral-matrix-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

vector<vector<int>> generateMatrix(int n) {
    
    vector<vector<int>> res;
    if(n == 0) {
        return res;
    }
    
    for(int i = 0; i < n; i++) {
        vector<int> temp(n);
        res.push_back(temp);
    }
    
    int value = 0;
    
    
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;
    
    while (1) {
        for(int i = left; i<= right; i++) {
            value++;
            res[top][i] = value;
        }
        top++;
        if(top > bottom) {
            break;
        }
        
        for(int i = top; i <= bottom; i++) {
            value++;
            res[i][right] = value;
        }
        right--;
        if(left > right) {
            break;
        }
        
        for(int i = right; i >= left; i--) {
            value++;
            res[bottom][i] = value;
        }
        bottom--;
        if(top > bottom) {
            break;
        }
        
        for(int i = bottom; i >= top; i--) {
            value++;
            res[i][left] = value;
        }
        left++;
        if(left > right) {
            break;
        }
    }
    
    return res;
    
}

void cusPrintf(vector<vector<int>> res) {
    for(auto val:res) {
        for(auto val2:val) {
            cout << val2 << " ";
        }
        cout << endl;
    }
}
int main(int argc, const char * argv[]) {

    vector<vector<int>> res= generateMatrix(0);
    
    cusPrintf(res);
    return 0;
}
