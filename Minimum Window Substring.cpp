#include <iostream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;


string min_length_window(string str , string pattern){
    int n = str.length();
    int m = pattern.length();
    if(n < m){
        return "";
    }

    unordered_map<char , int> frq_str , frq_pattern;
    int total_unique_characters = 0;
    for(int i = 0 ; i < m ; i++){
        if(frq_pattern.count(pattern[i]) == 0){
            total_unique_characters++;
        }
        frq_pattern[pattern[i]]++;
    }
    int found_unique_characters = 0;
    int start , end;
    start = 0;
    end = n-1;
    int s , e;
    s = 0;
    e = 0;
    int checker = 0;
    for(int i = 0 ; i < n ; i++){
        frq_str[str[i]]++;
        if(frq_str[str[i]] == frq_pattern[str[i]]){//we found correct frequency mathch
            found_unique_characters++;
            if(found_unique_characters == total_unique_characters){
                e = i;
                break;
            }
        }
        checker = i+1;
    }
    //cout<<checker<<"and"<<n<<endl;
    if(checker == n){ //no word found with all characters in pattern
        return "";
    }
    //shrink
    while(frq_str[str[s]] != frq_pattern[str[s]]){
        frq_str[str[s]]--;
        s++;
    }
    int minimum_window_size = INT_MAX;
    if( (e - s + 1) < minimum_window_size){
        start = s;
        end = e;
        minimum_window_size = e - s + 1;
    }
    int idx = e+1;
    while(idx < n){
        ///expand
        while(idx < n and str[idx] != str[s]){
            frq_str[str[idx]]++;
            idx++;
        }
        //cout<<idx<<endl;
        //cout<<frq_str[str[s]]<<" "<<frq_pattern[str[s]]<<endl;
        if(idx < n and str[idx] == str[s]){
            //shrink
            e = idx;
            frq_str[str[e]]++;
            while(frq_str[str[s]] != frq_pattern[str[s]]){
                frq_str[str[s]]--;
                //cout<<"HUA"<<endl;
                s++;
            }
        }
        if( (e - s + 1) < minimum_window_size){
            start = s;
            end = e;
            minimum_window_size = e - s + 1;
        }
        idx++;
    }
    string ans = "";
    //cout<<s<<" "<<e<<endl;
    for( ; start <= end ; start++){
        ans += str[start];
    }
    //cout<<minimum_window_size<<endl;
    return ans;
}

int main(){
    string str = "bdab";
    string pattern = "ab";
    cout<<min_length_window(str , pattern)<<endl;
    return 0;
}
