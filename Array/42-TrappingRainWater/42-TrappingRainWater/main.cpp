//
//  main.cpp
//  42-TrappingRainWater
//
//  Created by zhoujian on 2019/11/20.
//  Copyright © 2019 zhoujian. All rights reserved.
//
#include <iostream>
#include "vector"
#include "stack"
using namespace std;

/*
 接雨水
 https://leetcode-cn.com/problems/trapping-rain-water/
 */

/*
 解法三：单调递减栈
 */
int trap3(vector<int>& height) {
    //高度h单调递减的栈，存储
    stack<int> s;
    int ans = 0;
    for(int i = 0; i < height.size(); i++){
        while(!s.empty() && height[i] >= height[s.top()]){
            int top = s.top();
            s.pop();
            if(s.empty()) {
                break;
            }
            int sWidth = i - s.top() - 1;
            int sHeight = min(height[i], height[s.top()]) - height[top];
            ans += sWidth*sHeight;
        }
        s.push(i);
    }
    return ans;
}

/*
 解法二：1. 扫描一遍，找到最高的柱子，这个柱子将数组分为两半; 2. 处理左边一半; 3. 处理右边一半。
 */

int tarp2(vector<int> &height) {
    
    int res = 0;
    
    int maxHeight = 0;
    int maxIndex = 0;
    for(int i = 0; i < height.size(); i++) {
        if(height[i] > maxHeight) {
            maxHeight = height[i];
            maxIndex = i;
        }
    }
    
    int left = 0;
    int right = maxIndex;
    int leftHeight = 0;
    while (left < right) {
        if(leftHeight > 0 && height[left] < leftHeight) {
            res += leftHeight - height[left];
        }
        else {
            leftHeight = height[left];
        }
        left++;
    }
    
    left = maxIndex;
    right = (int)height.size()-1;
    int rightHeight = 0;
    while (left < right) {
        if(rightHeight > 0 && height[right] < rightHeight) {
            res += rightHeight - height[right];
        }
        else {
            rightHeight = height[right];
        }
        right--;
    }
    return res;
}


/*
 解法一：双指针:
 这个算法需要 left 和 right 两个指针分别指向数组的首尾位置，从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是 left 指向的值，则从左向右扫描，如果较小值是 right 指向的值，则从右向左扫描，若遇到的值比当较小值小，则将差值存入结果，如遇到的值大，则重新确定新的窗口范围
 */
int tarp1(vector<int> &height) {
    int res = 0;
    int left = 0;
    int right = (int)height.size()-1;
    while (left < right) {
        int minValue = min(height[left], height[right]);
        if(minValue == height[left]) {
            left++;
            while (left < right && height[left] < minValue) {
                res +=  minValue - height[left];
                left++;
            }
        }
        else {
            right--;
            while (left < right && height[right] < minValue) {
                res +=  minValue - height[right];
                right--;
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    vector<int> height = {0,1,0,2,1,0,1,6,2,1,2,1};
    int res = tarp1(height);
    cout << res << endl;
    
    return 0;
}
