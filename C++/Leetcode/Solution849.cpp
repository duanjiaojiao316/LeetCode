#include <vector>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int left = 0;
        while (seats[left] == 0) {
            left++;
        }
        int maxDistance = left;  // 计算座位最左边座位距离第一个人的座位的距离
        int right;
        while (left < n) {
            right = left + 1;
            while(right < n && seats[right] == 0) {
                right++;
            }
            // 求出最大距离
            if (right < n) { // 计算两个人之间的最大距离
                maxDistance = max(maxDistance, (right - left) / 2);
            } else { // 计算座位右边 最后一个人距离最右边座位的最大距离
                maxDistance = max(maxDistance, right - 1 - left);
            }
            
            left = right;
        }
        return maxDistance;

    }
};

int main() {
    vector<int> seats = {1,0,0,0,1,0,0,0,0,0,0,1}; // left = 0,4,11
    vector<int> seats1 = {1,0,0,0}; // left = 0,4,11
    Solution s = Solution();
    s.maxDistToClosest(seats1);
    return 0;
}