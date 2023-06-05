#include <vector>
using namespace std;

class Difference
{
private:
    vector<int> diff;
public:
    Difference(vector<int>& nums){
        int m = nums.size();
        if(m == 0) return;
        diff.resize(m);
        diff[0] = nums[0];
        for(int i = 1; i < m; i++){
            diff[i] = nums[i] - nums[i-1];
        }
    }

    void Difference::increment(int i, int j, int val){
        diff[i] += val;
        if(j + 1 < diff.size()){
            diff[j+1] -= val;
        }
    }

    void Difference::decrement(int i, int j, int val){
        diff[i] -= val;
        if(j + 1 < diff.size()){
            diff[j+1] += val;
        }
    }

    vector<int> Difference:: result() {
        vector<int> res = vector<int>(diff.size());
        res[0] = diff[0];
        for(int i = 1; i < diff.size(); i++){
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};