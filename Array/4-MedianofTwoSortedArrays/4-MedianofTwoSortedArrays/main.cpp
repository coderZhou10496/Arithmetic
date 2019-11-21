//
//  main.cpp
//  4-MedianofTwoSortedArrays
//
//  Created by zhoujian on 2019/11/21.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int findMedianSortedArraysCore(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if(i >= nums1.size()) {
        return nums2[j + k - 1];
    }
    if(j >= nums2.size()) {
        return nums1[i + k - 1];
    }
    if(k == 1) {
        return min(nums1[i], nums2[j]);
    }
    int midValue1 = (i + k/2 - 1 < nums1.size()) ? nums1[i + k/2 - 1] : INT_MAX;
    int midValue2 = (j + k/2 - 1 < nums2.size()) ? nums2[j + k/2 - 1] : INT_MAX;
    if(midValue1 < midValue2) {
        return findMedianSortedArraysCore(nums1, i + k/2, nums2, j , k - k/2);
    }
    else {
        return findMedianSortedArraysCore(nums1, i, nums2, j + k/2 , k - k/2);
    }
    
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int length1 = (int)nums1.size();
    int length2 = (int)nums2.size();
    int totalLength = length1 + length2;
    double res = 0;
    if(totalLength%2 == 0) {
        res =  (findMedianSortedArraysCore(nums1, 0, nums2, 0, totalLength/2) + findMedianSortedArraysCore(nums1, 0, nums2, 0, totalLength/2 + 1)) * 0.5;
    }
    else {
        res =  findMedianSortedArraysCore(nums1, 0, nums2, 0, totalLength/2 + 1);
    }

    return res;
}

int main(int argc, const char * argv[]) {

//    vector<int> nums1 = {1, 3};
//    vector<int> nums2 = {2};
    
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    
    
    return 0;
}
