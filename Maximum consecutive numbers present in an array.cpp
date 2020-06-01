#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int streak(int arr[] , int n){
    if(n == 0){
        return -1;
    }
    int ans = 0 , count = 0;
    int mini = INT_MAX , maxi = INT_MIN;
    unordered_map<int , int> freq;
    for(int i = 0 ; i < n ; i++){
        freq[arr[i]]++;
        mini = min(mini , arr[i]);
        maxi = max(maxi , arr[i]);
    }
    for( ; mini <= maxi ; mini++){
        if(freq.count(mini)){
            count++;
        }
        else{
            ans = max(count , ans);
            count = 0;
        }
    }
    return ans;
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
    cout<<streak(arr , n)<<endl;
    return 0;
}
