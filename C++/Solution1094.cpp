#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> diff;

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int m = trips.size();
        int n = trips[0].size();
        diff.resize(1000);
        for(int i = 0; i < m; i++){
            increment(trips[i][1], trips[i][2], trips[i][0]);
        }
        return result(capacity);
    }

    void increment(int i, int j, int val){
        diff[i] += val;
        if(j+1 < diff.size() ){
            diff[j] -= val;
        }
    }

    bool result(int capacity){
        vector<int> res = vector<int>(diff.size());
        res[0] = diff[0];
        if(res[0] > capacity) return false;
        for(int i = 1; i < diff.size(); i++){
            res[i] = diff[i] + res[i-1];
            if(res[i] > capacity){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> bookings = vector<vector<int>>(2, vector<int>(3));
    bookings = { {9,0,1},{3,3,7}};
    Solution s = Solution();
    // bool res = s.carPooling(bookings,4);
    // cout<< res <<endl;

    bool res1 = s.carPooling(bookings,4);
    cout<< res1 <<endl;
    return 0;
}