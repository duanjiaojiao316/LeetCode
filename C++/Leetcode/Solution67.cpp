//67. 二进制求和
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        string ans = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        int cnt = max(m, n);

        for (int i = 0; i < cnt; i++) {
            carry += i < m? a[i] - '0' : 0;
            carry += i < n? b[i] - '0' : 0;
            ans.push_back(carry % 2 + '0');
            carry /= 2;
        }
        if (carry == 1) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

int main() {
    Solution s = Solution();
    string a = "1010";
    string b = "1011";
    cout<< s.addBinary(a, b) <<endl;
}