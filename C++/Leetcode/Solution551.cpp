#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                absent++;
                if (absent >= 2) {
                    return false;
                }
            } 
            if (s[i] == 'L') {
                late++;
                if (late >= 3) {
                    return false;
                }
            } else {
                late = 0;
            }
        }
        return true;
    }
};