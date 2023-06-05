#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return 0;
        }

        int m = num1.length();
        int n = num2.length();
        string ans;

        for (int i = n - 1; i >= 0; i--) {
            int x = num2[i] - '0';
            int carry = 0; // 进位
            string cur_ans = "";

            for (int j = n - 1; j > i; j--) {
                cur_ans.push_back(0);
            }


            for (int j = m - 1; j >= 0; j--) {
                int y = num1[j] - '0';
                int mul = x * y + carry;
                carry = mul / 10;
                cur_ans.push_back(mul % 10);
            }
            while (carry != 0) {
                cur_ans.push_back(carry % 10);
                carry /= 10;
            }
            reverse(cur_ans.begin(), cur_ans.end());
            for (auto &c : cur_ans) {
                c += '0';
            }
            // 将cur_ans 与cur 相加
            ans = addStrings(cur_ans, ans);
            
        }
        return ans;
    }


    string addStrings(string &num1, string &num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};

int main() {
    Solution s = Solution();
    s.multiply("123", "456");
    return 0;
}