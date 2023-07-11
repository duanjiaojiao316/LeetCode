#include <vector>
#include <iostream>
using namespace std;


class Solution {
private: 
    vector<int> diff;

public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> res = vector<int>(n,0);
        int m = bookings.size();
        diff.resize(n,0);
        for(int i = 0; i < m; i++) {
            increment(bookings[i][0] - 1, bookings[i][1] - 1, bookings[i][2]);
        }
        return result();
    }

    void increment(int i, int j, int val){
        diff[i] += val;
        if(j + 1 < diff.size()){
            diff[j+1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res = vector<int>(diff.size());
        res[0] = diff[0];
        for(int i = 1; i < diff.size(); i++){
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
    

};

int main() {
    vector<vector<int>> bookings = vector<vector<int>>(3, vector<int>(3));
    bookings = { {1,2,10},{2,3,20},{2,5,25} };
    Solution s = Solution();
    // vector<int> res = s.corpFlightBookings(bookings,5);
    // int n = res.size();
    // for(int i = 0; i < n; i++){
    //     cout<<res.at(i)<<endl;
    // }

    bookings = {{1,2,10},{2,2,15}};
    vector<int> res = s.corpFlightBookings(bookings,2);
    int n = res.size();
    for(int i = 0; i < n; i++){
        cout<<res.at(i)<<endl;
    }
    
    return 0;
}

