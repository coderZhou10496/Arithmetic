//
//  main.cpp
//  15-ThreeSum
//
//  Created by zhoujian on 2019/11/15.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

vector<vector<int>> threeNum(vector<int>& nums, int target) {
    
    vector<vector<int>> result;
    int length = (int)nums.size();
    if(length < 3) {
        return result;
    }
    
    sort(nums.begin(),nums.end());
    
    for(int i = 0; i < length; i++) {
        
        int left = i + 1;
        int right = length - 1;
        
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        while (left < right) {
            
            
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == target) {
                
                vector<int> v1 = {nums[i], nums[left], nums[right]};
                result.push_back(v1);
                left++;
                right--;
                while (left < right && nums[left] == nums[left-1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right+1]) {
                    right--;
                }
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
    }

    return result;
    
}



int main(int argc, const char * argv[]) {
    
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = threeNum(nums, 0);
        
    for(int i = 0; i < result.size(); i++) {
        vector<int> v = result[i];
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << endl;
        }
        cout << endl;
    }
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
