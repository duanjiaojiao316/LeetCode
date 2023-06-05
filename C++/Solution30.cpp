#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        map<string, int> need;
        map<string, int> diff;

        vector<int> res;

        for(string s : words) {
            need[s]++;
        }

        int m = words.size();
        int n = words[0].size();
        int all_len = m * n;
        int str_len = s.length();
        

        for (int i = 0; i <= str_len - all_len; i++) {
            
            int valid = 0;

            for (int j = 0; j < m; j++) {
                string str_tmp = s.substr(i + j * n, n);
                if (!need.count(str_tmp)){
                    break;
                }
                diff[str_tmp]++;
                
                if (diff[str_tmp] == need[str_tmp]) {
                    valid++;
                }
            }
            if(valid == need.size()) {
                res.push_back(i);
            }
            diff.clear();
        }

        return res;

    }
};

int main() {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution solution = Solution();
    solution.findSubstring(s, words);
    return 0;
}