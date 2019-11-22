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
            if(nums[i] < exchangValue) {
                if(nums[i] > nums[index]) {
                    exchangIndex = i;
                    exchangValue = nums[i];
                }
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
