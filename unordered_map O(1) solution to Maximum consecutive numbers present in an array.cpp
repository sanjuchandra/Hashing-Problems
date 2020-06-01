#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;


int max_streak(int arr[] , int n){
    if(n == 0){
        return -1;
    }
    unordered_map<int , int> mp;
    int max_streak_len = 0;
    for(int i = 0 ; i < n ; i++){
        if(mp.count(arr[i])){
            continue;
        }
        int len1 = 0;
        int len2 = 0;
        if(mp.count(arr[i]-1)){
            len1 = mp[arr[i]-1];
        }
        if(mp.count(arr[i]+1)){
            len2 = mp[arr[i]+1];
        }
        int new_streak_len = 1 + len1 + len2;
        int lb,rb;
        lb = arr[i] - len1;
        rb = arr[i] + len2;
        mp[lb] = new_streak_len;
        mp[rb] = new_streak_len;
        if(len1 and len2){ //both not zero
            mp[arr[i]] = new_streak_len;
        }
        max_streak_len = max(max_streak_len , new_streak_len);
    }
    return max_streak_len;
}

int main(){
    /*int n;
    cin>>n;
    int arr[1000000000] = {0};
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }*/
    //int arr[] = {1, 94, 93, 1000, 5, 92, 78};
    int arr[] = {1, 5, 92, 4, 78, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<max_streak(arr , n)<<endl;
    return 0;
}
