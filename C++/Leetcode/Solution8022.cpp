#include <vector>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int add_num = n++;
        
        vector<int> res; // 存放最美数组
        int left= 1;
        int right = 2;
        
        res.push_back(left);
        int left_index = 0;
        while (res.size() < n) {
            while (right < add_num && left + right < target) {
                res.push_back(right);
                right++;
            } 
            if (left + right == target) {
                res.push_back(add_num);
                add_num++;
                
            } else {
                left_index++;
                left = res[left_index];
                right = res[left_index + 1];
            }
        }
    }
};