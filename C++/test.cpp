#include<iostream>
#include<vector>
using namespace std;

void fun(vector<int> arr) {
    for(int a: arr) {
        cout<<"---"<<a;
    }
    arr[1] = 100;
}

int main() {
    vector<int> arr = vector<int>{5,5};
    fun(arr);
    for(int a: arr) {
        cout<<"+++"<<a;
    }

    return 0;
}
