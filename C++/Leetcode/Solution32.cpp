#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()){
                idx.push_back(stk.top());
                stk.pop();
                idx.push_back(i);
            }
        }

        sort(idx.begin(), idx.end());

        int i = 0;
        int ans = 0;
        while (i < idx.size()) {
            int j = i;
            while(j < idx.size() - 1 && idx[j] + 1 == idx[j + 1]){
                j++;
            }
            ans = max(ans, j - i + 1);
            i = j + 1;
        }
        return ans;
    }
};


// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> sta;
//         sta.push(-1);
//         int len=0;
//         for(int i = 0; i < s.length(); i++){
//             if(s[i] == '(') sta.push(i);
//             else{
//                 sta.pop();
//                 if(sta.empty()) sta.push(i);
//                 else{
//                     len = max(len, i - sta.top());
//                 }

//             }
//         }
//         return len;
//     }
// };


class Solution32 {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> dp = vector<int>(n);


        for(int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                dp[i] = 0;
            } else {
                if (i - 1 >= 0 && s[i - 1] == '(' ) {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                } else if (i - 1 >= 0 && s[i - 1] == ')') {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = i - dp[ i - 1] - 2 >= 0 ? dp[i - 1] + dp[i - dp[ i - 1] - 2] + 2 : dp[i - 1] + 2;
                    }
                } 
            }
        }
        int res = *max_element(dp.begin(), dp.end());

        return res;

    }
};

int main() {
    Solution32 s = Solution32();
    string str = "";
    s.longestValidParentheses(str);
}