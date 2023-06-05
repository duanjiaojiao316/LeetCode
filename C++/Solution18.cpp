#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        long sum;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        if(size < 4) {
            return res;
        }
        for(int i = 0; i < size - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            if((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target){
                break;
            }
            if ((long) nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target){
                continue;
            }
            for (int j = i + 1; j < size - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if((long) nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target){
                    continue;
                }
                int left = j + 1;
                int right = size - 1;
                while(left < right) {
                    sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target){
                        right--;
                    }else if(sum < target){
                        left++;
                    }else if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        left++;
                        right--;
                    } 
                    
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = vector<int>{-1, -2,  0 , 0 ,2 , 1};
    s.fourSum(nums, 0);
    return 0;
}

class Solution {
public:
        vector<vector<int>> fourSum(vector<int> &nums, int target) {

        // 排序
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        // 临时变量（避免一些重复计算）
        int size = nums.size(), e1 = size - 3, e2 = size - 2,e3= size - 1, left, right, tmp;
        // 目标和
        long sum;

        // 第一个和第二个数通过两层for循环确定
        // 第三个和第四个数通过双指针确定
        for (int i = 0; i < e1; ++i) {

            // 目前目标和为sum
            sum = target;

            // 剪枝
            // 1.去除因第一个数导致的重复解
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            // 2.此后无解（组合最小值已大于sum）
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > sum) {
                break;
            }
            // 3.若以num[i]打头的组合的最大值小于sum，说明没有满足条件的以num[i]打头的组合
            //   第一层for循环已经确保此处size至少为4
            if ((long) nums[i] + nums[e3] + nums[e2] + nums[e1] < sum) {
                continue;
            }

            // 第一个数确定为nums[i]
            sum -= nums[i];

            for (int j = i + 1; j < e2; ++j) {

                // 剪枝
                // 1.去除因第二个数导致的重复解
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 2.此后无解（组合最小值已大于target）
                if ((long) nums[j] + nums[j + 1] + nums[j + 2] > sum){
                    break;
                }
                // 3.若第二个数为num[j]的组合的最大值小于target，说明没有满足条件的第二个数为num[j]的组合
                if ((long) nums[j] + nums[e3] + nums[e2] < sum) {
                    continue;
                }

                // 第二个数确定为nums[j]
                sum -= nums[j];

                // 剩下两个数采用双指针确定
                left = j + 1, right = size - 1;
                while (left < right) {
                    tmp = nums[left] + nums[right];
                    if (tmp == sum) {
                        // 找到一组合
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 去除第三个数导致的重复解
                        while (left < right && nums[left] == nums[left + 1])left++;
                        // 去除第四个数导致的重复解
                        while (left < right && nums[right] == nums[right - 1])right--;
                        // 下一组合
                        left++, right--;
                    } else if (tmp >= sum) {
                        right--;
                    } else {
                        left++;
                    }
                }

                // 恢复上一层目标和
                sum += nums[j];
            }
        }
        return res;
    }
};
