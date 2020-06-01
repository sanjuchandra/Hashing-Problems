#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <vector>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int , int> mx , my;
    for(int i = 0 ; i < n ; i++){
        mx[A[i]]++;
        my[B[i]]++;
    }
    int mod = 1000000007;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int n1 = mx[A[i]];
        int n2 = my[B[i]];
        ans += ((n1-1)%mod)*((n2-1)%mod)%mod;
        ans %= mod;
    }
    return ans%mod;
}

int main(){
    vector<int> A{1, 1, 2};
    vector<int> B{1 , 2 , 1};
    cout<<solve(A , B)<<endl;
    return 0;
}
