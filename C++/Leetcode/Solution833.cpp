#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// indices 有序的情况下可以
class Solution1 {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        int add_size = 0;
        for (int i = 0; i < k; i++) {
            int index = s.find(sources[i]);
            if (index != s.size() && index == indices[i] + add_size) {

                s.replace(index, sources[i].size(), targets[i]);
                add_size += targets[i].size() - sources[i].size();
            }
        }
        return s;
    }
};

// indices 无序状态怎么处理呢
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();

        map<int,int> indicesMap;
        for(int i = 0; i < indices.size(); ++i){
            indicesMap[indices[i]] = i;//排序+记录indices原来的位置
        };
        int add_size = 0;
        for (pair<int, int> i: indicesMap) {
            string temp = sources[i.second];
            int temps = s.size();
            int index = s.find(sources[i.second]);
            while (index < s.size() && index != i.first + add_size) {
                index = s.find(sources[i.second], index + 1);
            }
            
            if (index < s.size() && index == i.first + add_size) {

                s.replace(index, sources[i.second].size(), targets[i.second]);
                add_size += targets[i.second].size() - sources[i.second].size();
            }
        }
        return s;
    }
};
int main () {
    string  s = "ehvfwtrvcodllgjctguxeicjoudmxbevzrvravkidnricwsbnxmxvdckzahmqzbrlqugtmjvoqbxarmlgjeqcorhnodvnoqfomdp";
    vector<int> indices = {1,31,44,70,23,73,76,92,90,86,42,4,50,17,53,20,55,15,38,64,25,9,7,68,60,88,96,47,57,34,81,78,28};
    vector<string> sources = {"hvf","vzr","cw","jvo","jo","qb","ar","noqf","dv","rh","ri","wt","mx","gux","dc","eic","kz","ct","kidn","lq","ud","odll","vc","tm","qz","no","om","bn","ahm","vra","jeqco","ml","xb"};
    vector<string> targets = {"ajq","zb","r","fai","e","zs","io","snxd","nw","oi","ofb","quq","gj","nsys","dk","sf","muj","ll","hqx","k","n","ptrya","f","qek","u","dhj","e","kr","waj","rvkr","roaoeq","mci","djw"};
    Solution so = Solution();
    cout << so.findReplaceString(s, indices, sources, targets);
    cout << s.find("cd");
    
}