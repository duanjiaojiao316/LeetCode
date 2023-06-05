#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;

/**
 * 给你一个字符串 s 和一个整数 k ，
 * 请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。
 * 返回这一子串的长度。
 * 
 * 输入：s = "ababbc", k = 2 
 * 输出：5 
 * 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int record[26];     //记录滑动窗口内每个字符出现的次数，字符'a'对应位置0，'b'对应位置1...
        for(int i=1; i<=26; ++i) {      //每个循环中，滑动窗口内只能有i个不同字符
            memset(record, 0, sizeof(record));
            int left = 0, right = 0;
            int diff_count = 0, count = 0;      //分别代表滑动窗口中不同的字符数、出现次数大于等于k的字符数
            while(right < s.length()) {
                //向右扩大窗口，即把字符s[right]加入窗口
                int add_index = s[right] - 'a';     //字符s[right]（将要加入窗口的字符）在record中对应的位置
                record[add_index] += 1;
                if(record[add_index] == 1)
                    diff_count++;
                if(record[add_index] == k)
                    count++;
                right++;

                //窗口内只能包含i个不同字符，如果超过了就缩减窗口，即把字符s[left]移出窗口
                while(left < right && diff_count > i) {
                    int del_index = s[left] - 'a';  //字符s[left]（将要删除的字符）在record中对应的位置
                    if(record[del_index] == k)
                        count--;
                    if(record[del_index] == 1)
                        diff_count--;
                    record[del_index] -= 1;
                    left++;
                }
                //如果窗口内的不同字符数 == 出现次数大于等于k的字符数 == 当前循环限制的不同字符数
                if(diff_count == i && diff_count == count)
                    //说明窗口内的每个字符出现次数都大于等于k，此时的窗口是一个可行解
                    res = max(res, right - left);
            }
        }
        return res;
    }
};