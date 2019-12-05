//
//  main.cpp
//  81-SearchinRotatedSortedArrayII
//
//  Created by zhoujian on 2019/12/5.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 
 ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 
 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 
 示例 1:
 
 输入: nums = [2,5,6,0,0,1,2], target = 0
 输出: true
 示例 2:
 
 输入: nums = [2,5,6,0,0,1,2], target = 3
 输出: false
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

bool search(vector<int>& nums, int target) {
    int length = (int)nums.size();
    if(length == 0) {
        return false;
    }
    int left = 0;
    int right = length-1;
    
    while (left <= right) {
        int mid = (left + right)/2;
        if(nums[mid] == target || nums[left] == target || nums[right] == target) {
            return true;
        }
        
        /* 相对于No.32数组中没有重复元素这一题，加了这个判断
         注意：这里是判读了nums[right] == nums[mid]，因为下面的判断是先判断了 nums[mid] < nums[right]
         */
        if (nums[right] == nums[mid]) {
            right--;
            continue;
        }
        
        
        if(nums[mid] < nums[right]) {
            if(target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else {
            if(target < nums[mid] && target >= nums[left]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
    return false;
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {3,1,2,2,2};
    bool res = search(nums,1);
    cout << res << endl;
    return 0;
}
