#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    Solution(){}
    vector<int> getMinKNumsByBFPRT(vector<int>& arr, int k) {
        if (k > arr.size()) {
            return arr;
        }
        if (k < 1) {
            return vector<int>();
        }
        int min_k_th_num = getMinKthByBFPRT(arr, k);
        vector<int> min_k_nums = vector<int>(k);
        int index = 0;

        for (int i = 0; i != arr.size(); i++) {
            if (arr[i] < min_k_th_num) {
                min_k_nums[index++] = arr[i];
            }
        }

        for (;index != min_k_nums.size(); index++) {
            min_k_nums[index] = min_k_th_num;
        }
        return min_k_nums;
    }

    int getMinKthByBFPRT(vector<int>& arr, int k) {
        return select(arr, 0, arr.size() - 1, k - 1);
    }

    int select(vector<int>& arr, int begin, int end, int i) {
        if (begin == end) {
            return arr[begin];
        }

        int pivot = medianOfMedians(arr, begin, end);
        vector<int> pivot_range = partition(arr, begin, end, pivot);
        if (i >= pivot_range[0] && i <= pivot_range[1]) {
            return arr[i];
        } else  if(i < pivot_range[0]){
            return select(arr, begin, pivot_range[0] - 1, i);
        } else {
            return select(arr, pivot_range[1] + 1, end, i);
        }
    }
    int medianOfMedians(vector<int>& arr, int begin, int end) {
        int num = end - begin + 1;
        int offset = num % 5 == 0 ? 0 : 1;
        vector<int> median_arr = vector<int>(num / 5 + offset);
        for (int i = 0; i < median_arr.size(); i++) {
            int beginI = begin + i * 5;
            int endI = beginI + 4;
            median_arr[i] = getMedian(arr, beginI, min(endI, end));
        }
        return select(median_arr, 0, median_arr.size() - 1, median_arr.size()/2);

    }

    vector<int> partition(vector<int>& arr, int begin, int end, int pivotValue) {
        int small = begin - 1;
        int cur = begin;
        int big = end + 1;
        while (cur != big) {
            if (arr[cur] < pivotValue) {
                swap(arr, ++small, cur++);
            } else if (arr[cur] > pivotValue) {
                swap(arr, cur, --big);
            } else {
                cur++;
            }
        }
        vector<int> range = vector<int>{small + 1, big - 1};
    
        return range;

    }

    int getMedian(vector<int>& arr, int begin, int end) {
        insertionSort(arr, begin, end);
        int sum = end + begin;
        int mid = (sum / 2) + (sum % 2);
        return arr[mid];
    }

    void insertionSort(vector<int>& arr, int begin, int end) {
        for (int i = begin + 1; i != end + 1; i++) {
            for (int j = i; j != begin; j--) {
                if (arr[j - 1] > arr[j]) {
                    swap(arr, j - 1, j);
                } else {
                    break;
                }
            }
        }
    }

    void swap(vector<int>& arr, int index1, int index2) {
        int tmp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = tmp;
    }
};

int main() {
    vector<int> arr = {1,3,5,7,4,6,8};
    int k = 1;
    Solution solution = Solution();
    vector<int> res = solution.getMinKNumsByBFPRT(arr, k);
    cout<<"[";
    for(int a : res) {
        cout<<a<<" ";
    }
    cout<<"]";

    return 0;
}

