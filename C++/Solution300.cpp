#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(),1);

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) {
                    dp[i] = max (dp[i], dp[j] + 1);
                }
            }
        }
        
        int res = 0;
        
        for(int i = 0; i < dp.size(); i++) {
            res = max (res, dp[i]);
        }
        
        return res;
    }
};

class Solution300
{
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int piles = 0;
        vector<int> top = vector<int>(n);
        for (int i = 0; i < n; i++ ) {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] >= poker) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(left == piles) {
                piles++;
            }
            top[left] = poker;
        }
        return piles;
    }
};
