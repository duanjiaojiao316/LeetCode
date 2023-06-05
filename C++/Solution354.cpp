#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        // sort(envelopes.begin(), envelopes.end(), compare);
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a[0]==b[0] ? b[1] < a[1] : a[0] < b[0];
        });
        vector<int> height = vector<int>(n);
        for(int i = 0; i < n; i++) {
            height[i] = envelopes[i][1];
        }
        return lengthOfLIS(height);
    }

    static bool compare(vector<int> a, vector<int> b) {
        return a[0]==b[0] ? b[1] < a[1] : a[0] < b[0];
    }

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

int main () {
    vector<vector<int>> envelops = {{5,6},{6,4},{6,7},{2,3},{5,4},{2,1}};
    Solution s = Solution();
    s.maxEnvelopes(envelops);
    return 0;
}