#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];

    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;

        for(int num : nums) {
            counts[num]++;
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};

class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                majority = num;
                count++;
            } else if (majority == num) {
                count++;
            } else {
                count--;
            }
        }
        return majority;
    } 
};

