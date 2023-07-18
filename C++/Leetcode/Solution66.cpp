#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >=0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            } 
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    vector<int> arr = {1,2,3};
    arr.insert(arr.begin(), 0);
    return 0;
}