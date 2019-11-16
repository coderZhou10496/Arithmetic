//
//  main.cpp
//  11-ContainMostWater
//
//  Created by zhoujian on 2019/11/15.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int maxWater(vector<int>& height) {
    int left = 0;
    int right = (int)height.size()-1;
    int result = 0;
    int current = 0;
    
    while (left < right) {
        current = min(height[left], height[right]) * (right-left);
        if(result < current) {
            result = current;
        }
        if(height[left] < height[right]) {
            left++;
        }
        else {
            right--;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int resut = maxWater(height);
    cout << resut << endl;
    return 0;
}
