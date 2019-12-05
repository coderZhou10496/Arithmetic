//
//  main.cpp
//  84-LargestRectangleinHistogram
//
//  Created by zhoujian on 2019/12/5.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

/*
 
 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 
 https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 */


// 暴力循环 n(^3) 果然超时
int largestRectangleArea1(vector<int>& heights) {
    
    int result = 0;
    int length = (int)heights.size();
    if(length == 0) {
        return length;
    }
    if(length == 1) {
        result = heights[0];
        return result;
    }
    
    int currentWidth = 1;
    while (currentWidth <= length) {
        
        int maxValue = 0;
        for(int i = 0; i < length-currentWidth+1; i++) {
            int minValue = heights[i];
            for(int j = i; j < i+currentWidth; j++) {
                minValue = min(minValue, heights[j]);
            }
            maxValue = max(maxValue, currentWidth * minValue);
        }
        result = max(result, maxValue);
        currentWidth++;
    }
    
    return result;
    
}




int largestRectangleArea2(vector<int>& heights) {
    
    int result = 0;
    int length = (int)heights.size();
    if(length == 0) {
        return 0;
    }
    if(length == 1) {
        return heights[0];
    }

    vector<int> leftMinVec(length);
    leftMinVec[0] = -1;
    
    for(int i = 1; i < length; i++) {
        int leftIndex = i - 1;
        while(leftIndex >= 0 && heights[leftIndex] >= heights[i]) {
            leftIndex = leftMinVec[leftIndex];
        }
        leftMinVec[i] = leftIndex;
    }
    
    vector<int> rightMinVec(length);
    rightMinVec[length-1] = length;
    for(int i = length-2; i >= 0; i--) {
        int rightIndex = i+1;
        while (rightIndex <= length-1 && heights[rightIndex] >= heights[i]) {
            rightIndex = rightMinVec[rightIndex];
        }
        rightMinVec[i] = rightIndex;
    }
    
    for(int i = 0; i < length; i++) {
        result = max(result, heights[i] * (rightMinVec[i] - leftMinVec[i] - 1));
    }
    return result;
    
}

// 使用栈
int largestRectangleArea3(vector<int>& heights) {
    
    int result = 0;
    int length = (int)heights.size();
    if(length == 0) {
        return 0;
    }
    
    stack<int> s;
    
    for(int i = 0; i < length; i++) {
        while (!s.empty() && heights[i] <= s.top()) {
            int topValue = s.top();
            s.pop();
            result = max(result, heights[topValue] * (s.empty() ? i : i - s.top() - 1));
        }
        s.push(i);
    }
    
    
    return result;
    
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1,5,6,2,3};
    int res = largestRectangleArea3(nums);
    cout << res << endl;
    return 0;
}
