//
//  main.cpp
//  34-FindFirstAndLastPositionInSortedArray
//
//  Created by zhoujian on 2019/11/23.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 
 你的算法时间复杂度必须是 O(log n) 级别。
 
 如果数组中不存在目标值，返回 [-1, -1]。
 
 示例 1:
 
 输入: nums = [5,7,7,8,8,10], target = 8
 输出: [3,4]
 示例 2:
 
 输入: nums = [5,7,7,8,8,10], target = 6
 输出: [-1,-1]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */


/*
 题解：
 分别求出左边和右边的index
 
 */

vector<int> searchRange(vector<int>& nums, int target) {
    
    vector<int> res;
    int leftRes = -1;
    int rightRes = -1;
    
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = (left + right)/2;
        int midValue = nums[mid];
        if(midValue == target && (mid == 0 || nums[mid-1] != target)) {
            leftRes = mid;
            break;
        }
        
        if(midValue >= target) {
            right = mid - 1;
            
        }
        else {
            left = mid+1;
        }
    }
    
    left = 0;
    right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = (left + right)/2;
        int midValue = nums[mid];
        if(midValue == target && (mid == nums.size()-1 || nums[mid+1] != target)) {
            rightRes = mid;
            break;
        }
        
        if(midValue <= target) {
            left = mid+1;
        }
        else {
            right = mid - 1;
        }
    }
    res.push_back(leftRes);
    res.push_back(rightRes);
    return res;
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1,7,7,7,7,7};
    vector<int> res = searchRange(nums, 7);
    for(auto val : res) {
        cout << val << endl;
    }

    return 0;
}
