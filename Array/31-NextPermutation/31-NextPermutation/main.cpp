//
//  main.cpp
//  31-NextPermutation
//
//  Created by zhoujian on 2019/11/22.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 
 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 
 必须原地修改，只允许使用额外常数空间。
 
 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/next-permutation
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */


void nextPermutation(vector<int> &nums) {
    
    int length = (int)nums.size();
    int index = -1;
    for(int i = length-1; i >= 1; i--) {
        if(nums[i-1] < nums[i]) {
            index = i - 1;
            break;
        }
    }
    
    if(index !=  -1) {
        int exchangIndex = 0;
        int exchangValue = INT_MAX;
        for(int i = index+1; i < length; i++) {
            if(nums[i] < exchangValue && nums[i] > nums[index]) {
                    exchangIndex = i;
                    exchangValue = nums[i];
            }
        }
        swap(nums[index],nums[exchangIndex]);
    }
    

    
    for(int i = index+1; i < length; i++) {
        
        int min = i;
        
        for(int j = i; j < length; j++) {
            if(nums[j] < nums[min]) {
                min = j;
            }
        }
        
        
        if(min != i) {
            swap(nums[i], nums[min]);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1,2,3};
    vector<int> nums2 = {3,2,1};
    vector<int> nums3 = {1,1,5};
    vector<int> nums4 = {3,8,2,7,6};
    nextPermutation(nums3);
    for(auto val:nums3) {
        cout << val;
        
    }
    cout << endl;
    
    return 0;
}
