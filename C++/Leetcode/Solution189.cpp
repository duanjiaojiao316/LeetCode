#include <vector>
using namespace std;

// 方法一：使用额外的数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newNums(n);

        for (int i = 0; i < n; i++) {
            newNums[(i + k) % n] = nums[i];
        }

        nums.assign(newNums.begin(), newNums.end());
    }
};

// 方法二：环状替换
class Solution {
    public:
    void rotate(vector<int>&nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);

        for (int start = 0; start < count; start++) {
            int current = start;
            int pre = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], pre);
                current = next;
            } while (start != current);
        }
    }
};