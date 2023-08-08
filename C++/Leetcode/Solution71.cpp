#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> splitPath;
        split(path, splitPath);
        vector<string> stack;

        for (string str : splitPath) {
            if (str == "..") {
                if (stack.size() != 0) {
                    stack.pop_back();
                }
            } else if (str== "." || str.empty()) {
                continue;
            } else {
                stack.push_back(str);
            }
        }
        string res = "";
        if (stack.empty()) {
            res = "/";
        } else {
            for (string name: stack) {
                res += "/" + name;
            }
        }
        return res;
        
    }

    void split(const string& s, vector<string>& tokens, char delim = '/') {
        tokens.clear();
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
    }
};