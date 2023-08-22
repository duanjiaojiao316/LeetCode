#include <string>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        int i = 0; int j = 0;

        while (i < n && j < n) {
            while (i < n && start[i] == '_') {
                i++;
            }

            while (j < n && target[j] == '_') {
                j++;
            }

            if (i < n && j < n) {
                if (start[i] != target[j]) {
                    return false;
                }
                if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
            
        }
        // start 和 target其中一个已经遍历到最后

        while (i < n) 
        {
            if (start[i] != '_') {
                return false;
            }
            i++;
        }

        while (j < n) {
            if (target[j] != '_') {
                return false;
            }
            j++;
        }
        return true;
        
    }
};

int main() {
    string start = "_L__R__R_";
    string target = "L______RR";
    Solution s = Solution();
    s.canChange(start, target);
    return 0;
}