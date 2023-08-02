#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s. size();
        bool dotFlag = false;
        bool eFlag = false;
        // 如果包含E或者e使用E或者e分割数字
        for (int i = 0; i < n; i++) {
            if ((s[i] == '+' || s[i] == '-') ) { 
                
                if (i == n - 1) { // + - 号不能结尾
                    return false;
                } else if (i > 0 && !(s[i - 1] == 'E' || s [i - 1] == 'e')) {
                    return false;
                }
                else if (i < n - 1 && (s[i + 1] == 'E' || s [i + 1] == 'e' || s[i + 1] == '+' || s[i + 1] == '-') ) {
                    return false;
                }
            } else if (s[i] == '.' ) {
                if (dotFlag) { // . 只能出现一次
                    return false;
                }
                dotFlag = true;
                if (i== 0 && i == n - 1) { // '.' 无效
                    return false;   
                } 
                if ( !((i + 1 < n && '0' <= s[i + 1] &&  s[i + 1] <= '9') || (i - 1 >= 0 && '0' <= s[i - 1] && s[i - 1] <='9'))) {
                    // . 的前后都没有数字 无效
                    return false;
                }
                
            } else if (s[i] == 'E' || s[i] == 'e') {
                if (eFlag) {
                    return false; // E e只能出现一次
                }
                eFlag = true;
                if (i == 0 || i == n-1) { // E 或者e 开头或者结尾 无效
                    return false;
                } else {
                    for (int j = i + 1; j < n; j++) { //  E之后为小数无效
                        if (s[j] == '.' ){
                            return false;
                        }
                    }
                    
                }
            } else if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z') { // 如果包含除了E和而之外的字母 无效
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s = Solution();
    s.isNumber("64.e3");
    vector<string> is = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1","53.5e93","64.e3"};

    for (int i = 0; i < is.size(); i++) {
        cout<<s.isNumber(is[i])<<" " << is[i] <<endl;
    }
    cout <<"-----------------------------------"<<endl;

    vector<string> isnot = {"bac", "1a", "1e","e3","99e2.5", "--6", "-+3","95a54e53","ee","..",".1.","4R", "4e+", "+E3", "+", "+-", "+2+3e5","6ee69","6e3e4","+.E3"};

    for (int i = 0; i < isnot.size(); i++) {
        cout<<s.isNumber(isnot[i])<<" " << isnot[i] <<endl;
    }

    // 0 是 false 1 是true
}