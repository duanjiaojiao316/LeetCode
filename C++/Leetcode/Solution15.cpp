#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution15 {
    vector<vector<int>> treeSum(vector<int> & nums){
        vector<vector<int>> res;
        int size = nums.size();
        if (size < 3)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++){
            if(nums[i] > 0){
                return res;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] > 0) {
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--; 
                }
            }
        }
        return res;
        
    }
};