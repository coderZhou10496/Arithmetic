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



// 左右边界法：每个位置i，找到其左边最近的高度小于heights[i]和右边最近的高度小于heights[i]的位置，称之为左边界和右边界
int largestRectangleArea2(vector<int>& heights) {
    
    int result = 0;
    int length = (int)heights.size();
    if(length == 0) {
        return 0;
    }
    if(length == 1) {
        return heights[0];
    }

    vector<int> leftMinIndexVec(length);
    leftMinIndexVec[0] = -1;
    
    for(int i = 1; i < length; i++) {
        int leftIndex = i - 1;
        while(leftIndex >= 0 && heights[leftIndex] >= heights[i]) { // 如果左边元素的高度大于height[i];
            leftIndex = leftMinIndexVec[leftIndex]; // 左边元素的左边界可能和当前元素相同，所以下一次进while条件判断一下
        }
        leftMinIndexVec[i] = leftIndex;
    }
    
    vector<int> rightMinIndexVec(length);
    rightMinIndexVec[length-1] = length;
    for(int i = length-2; i >= 0; i--) {
        int rightIndex = i+1;
        while (rightIndex <= length-1 && heights[rightIndex] >= heights[i]) {
            rightIndex = rightMinIndexVec[rightIndex];
        }
        rightMinIndexVec[i] = rightIndex;
    }
    
    for(int i = 0; i < length; i++) {
        result = max(result, heights[i] * (rightMinIndexVec[i] - leftMinIndexVec[i] - 1));
    }
    return result;
    
}

/*
 1.单调栈分为单调递增栈和单调递减栈
     11. 单调递增栈即栈内元素保持单调递增的栈
     12. 同理单调递减栈即栈内元素保持单调递减的栈
 
 2.操作规则（下面都以单调递增栈为例）
     21. 如果新的元素比栈顶元素大，就入栈
     22. 如果新的元素较小，那就一直把栈内元素弹出来，直到栈顶比新元素小
 
 3. 加入这样一个规则之后，会有什么效果
     31. 栈内的元素是递增的
     32. 当元素出栈时，说明这个新元素是出栈元素向后找第一个比其小的元素
     33. 当元素出栈后，说明新栈顶元素是出栈元素向前找第一个比其小的元素

*/

// 递增栈
int largestRectangleArea3(vector<int>& heights) {
    
    int result = 0;
    int length = (int)heights.size();
    if(length == 0) {
        return 0;
    }

    heights.push_back(0); // 注意，这里向数组添加了一个哨兵元素
    stack<int> s;

    for(int i = 0; i < length+1; i++) {
        while (!s.empty() && heights[i] <= heights[s.top()]) {
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
