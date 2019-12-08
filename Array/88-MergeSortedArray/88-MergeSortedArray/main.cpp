//
//  main.cpp
//  88-MergeSortedArray
//
//  Created by zhoujian on 2019/12/8.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 输出: [1,2,2,3,5,6]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m == 0 && n == 0) {
        return;
    }
    if(n == 0) {
        return ;
    }
    
    vector<int> v;
    int index1 = 0;
    int index2 = 0;

    
    while (index1 < m || index2 < n) {
        if(index1 < m && index2 < n) {
            if(nums1[index1] < nums2[index2]) {
                v.push_back(nums1[index1]);
                index1++;
            }
            else {
                v.push_back(nums2[index2]);
                index2++;
            }
        }
        else if (index1 < m) {
            v.push_back(nums1[index1]);
            index1++;
        }
        else {
            v.push_back(nums2[index2]);
            index2++;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        nums1[i] = v[i];
    }
}
int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    for(auto val : nums1) {
        cout << val << endl;
    }
    return 0;
}
