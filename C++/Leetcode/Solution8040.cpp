#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();

        auto f = [&] (string tail) {
            int i = num.rfind(tail[1]);
            if (i == string :: npos || i == 0) return n;
            i = num.rfind(tail[0], i - 1);
            if (i == string::npos) return n;
            return n - i - 2;
        };

        return min({n - (num.find('0') == string::npos), f("00"), f("25"), f("50"), f("75")});
        
    }
};