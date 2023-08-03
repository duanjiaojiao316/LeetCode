#include <string>
#include <vector>
using namespace std;

//  模拟过程实现方法
class Solution {
 public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> res;
    string new_line_str = "";
    bool inComment = false;
    for (string str : source) {
      int n = str.size();
      for (int i = 0; i < n; i++) {
        if (inComment) {  // 如果位于注释块中
          if (i + 1 < n && str[i] == '*' && str[i + 1] == '/') {
            inComment = false;
            i++;
          }
        } else {
          if (i + 1 < n && str[i] == '/' && str[i + 1] == '/') {
            break;
          } else if (i + 1 < n && str[i] == '/' && str[i + 1] == '*') {
            inComment = true;
            i++;
          } else {
            new_line_str += str[i];
          }
        }
      }
      if (!inComment && !new_line_str.empty()) {
        res.push_back(new_line_str);
        new_line_str = "";
      }
    }
    return res;
  }
};

#include <regex>
// 正则表达式
class Solution1 {
 public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> res;
    string str = "";
    for (string s : source) {
      str += s;
      str += '\n';
    }
    regex r{"//.*|/\\*(.|\n)*\\*/"};
    string str = regex_replace(str, r, "");

    string tmp = "";
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '\n') {
        if (tmp != "") {
          res.push_back(tmp);
        }
        tmp = "";
      } else {
        tmp += str[i];
      }
    }

    return res;
  }
};

// 状态机

class Solution2 {
 public:
  vector<string> removeComments(vector<string> &source) {}
};

#include <iostream>
int main() {
  Solution1 s = Solution1();
  vector<string> str = {"/*Test program */",
                        "int main()",
                        "{ ",
                        "  // variable declaration ",
                        "int a, b, c;",
                        "/* This is a test",
                        "   multiline  ",
                        "   comment for ",
                        "   testing */",
                        "a = b + c;",
                        "}"};
  s.removeComments(str);
}