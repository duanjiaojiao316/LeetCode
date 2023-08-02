#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int left, right = 0;

        vector<string> res;
        
        while (true) {
            left = right;
            int row_words_nums = 0;
            int row_words_length = 0;
            while (right < n && row_words_length + row_words_nums + words[right].size() <= maxWidth) {
                row_words_length += words[right].size();
                row_words_nums++;
                right++;
            }
            if (right <= n - 1) {
                //计算空格总数， 平均的空格数， 已经多出来的空格个数
                int spaceNums = maxWidth - row_words_length;
                if (row_words_nums == 1) {
                    res.push_back(words[left] + string(spaceNums, ' '));
                }else {
                    int avgSpace = spaceNums / (row_words_nums - 1);
                    int extraSpace = spaceNums % (row_words_nums - 1);
                    res.push_back(joinWords(words, left, right - 1, avgSpace, extraSpace));
                }
                
            }
            if (right == n) {
                int spaceNums = maxWidth - row_words_length;
                res.push_back(joinWordsTail(words, left, right - 1, spaceNums - (right - left) + 1));
                break;
            }
        }
        return res;

    }

    string joinWords(vector<string>& words, int left, int right, int avgSpace, int extraSpace) {
        string res = "";
        while (left < right) {
            res += words[left];
            res += string(extraSpace > 0 ? avgSpace + 1 : avgSpace, ' ');
            left++;
            extraSpace--;
        }
        res += words[left];
        return res;
    }
    string joinWordsTail(vector<string>& words, int left, int right, int spaceNums) {
        string res = "";
        while (left < right) {
            res += words[left] + ' ';
            left++;
        }
        res += words[left] + string(spaceNums, ' ');
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = s.fullJustify(words, 16);
    for (string str: res) {
        cout<<str<<endl;
    }

    vector<string> words1 = {"What","must","be","acknowledgment","shall","be"};
    res = s.fullJustify(words1, 16);
    for (string str: res) {
        cout<<str<<endl;
    }
    return 0;
}