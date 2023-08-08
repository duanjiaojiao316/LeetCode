#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0;
        int p2 = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                swap(nums[p0], nums[i]);
                p0++;
            } else if(i <= p2 && nums[i] == 2) {
                swap(nums[p2], nums[i]);
                p2--;
            }
        }

    }
};

int main() {
    
    return 0;
}