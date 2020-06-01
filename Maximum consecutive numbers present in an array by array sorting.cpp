#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;

int streak(int arr[] , int n){
    if(n == 0){
        return -1;
    }
    sort(arr , arr+n);
    int ans = 0;
    int count = 1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 1 ; i < n-1 ; i++){
        if(arr[i-1] + 1 == arr[i]){
            count++;
        }
        else if(arr[i-1] == arr[i]){
            continue;
        }
        else{
            ans = max(ans , count);
            count = 1;
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
