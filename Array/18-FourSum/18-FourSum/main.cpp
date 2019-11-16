//
//  main.cpp
//  18-FourSum
//
//  Created by zhoujian on 2019/11/16.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int length = (int)nums.size();
    if(length < 4) {
        return result;
    }
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < length-3; i++) {
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for(int j = i+1; j < length-2; j++) {
            
            if(j > i+1 &&  nums[j] == nums[j-1]) {
                continue;
            }
            
            int left = j+1;
            int right = length-1;
            
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                
                if(sum == 0) {
                    
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    while (left < right && nums[left] == nums[left-1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                }
                else if(sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
            
        }
    }
    
    return result;
    
    
}


int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1, 0, -1, 0, -2, 2};
//    vector<int> nums = {0,0,0,0};
    vector<vector<int>> result = fourSum(nums, 1);
    
    for(int i = 0; i < result.size(); i++) {
        vector<int> v = result[i];
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << endl;
        }
        cout << endl;
    }
    return 0;
}
