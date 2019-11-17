//
//  main.cpp
//  26-RemoveDuplicates
//
//  Created by zhoujian on 2019/11/17.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 
 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 示例 1:
 
 给定数组 nums = [1,1,2],
 
 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 示例 2:
 
 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 
 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 
 你不需要考虑数组中超出新长度后面的元素。
 */

int removeDuplicates(vector<int>& nums) {
    
    int length = (int)nums.size();

    int resultLength = 0;
    int validValue = 0;
    for(int i = 0; i < length; i++) {
        int currentValue = nums[i];
        if(i == 0) {
            validValue = currentValue;
            resultLength++;
            continue;
        }
        
        if(currentValue != validValue) {
            validValue = currentValue;
            resultLength++;
            nums[resultLength-1] = currentValue;
        }
    }
    return resultLength;
}

int main(int argc, const char * argv[]) {
//    vector<int> nums = {1,1,2};
//    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0};
    int result = removeDuplicates(nums);
    
    cout << "result:" << result << endl;
    for(int i = 0; i < result; i++) {
        cout << nums[i] << endl;
    }
    
    return 0;
}
