#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

int max_streak(int arr[] , int n){
    if(n == 0){
        return -1;
    }
    unordered_set<int> s;
    for(int i = 0 ; i < n ; i++){
        s.insert(arr[i]);
    }
    int count = 0;
    int max_streak_len = 0;
    for(int i = 0 ; i < n ; i++){
        int x = arr[i];
        if(s.find(x-1) != s.end()){
            continue;
        }
        else{
            count = 1;
            while(s.find(x + 1) != s.end()){
                count++;
                x += 1;
            }
        }
        max_streak_len = max(count , max_streak_len);
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
    int arr[] = {1, 5, 5 ,  5 ,  5 ,  5 ,  5 , 92, 4, 78, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<max_streak(arr , n)<<endl;
    return 0;
}
