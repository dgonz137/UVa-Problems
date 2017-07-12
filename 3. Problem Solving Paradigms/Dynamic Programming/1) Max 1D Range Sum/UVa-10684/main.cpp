/* 
 * File:   main.cpp
 * Author: David
 *
 * Created on June 17, 2017, 11:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 
 */
typedef vector<int> vi;
typedef vector<vi> vii;
vi arr;
int dp[10100][10100];

int solve(){
    int max = -1;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j >= 0; j--){
            if(i==j) dp[i][j] = arr[i];
            else{
                dp[i][j] = dp[i-1][j] + arr[i];
            }
            if(dp[i][j] > max) max = dp[i][j];
        }
    }
    return max;
}
int main() {
    int n,x,ans;
    cin >> n;
    while(n!=0){
        while(n--){
            cin >> x;
            arr.push_back(x);
        }
        if((ans = solve()) > 0) cout << "The maximum winning streak is " << ans << "." << endl;
        else cout << "Losing streak." << endl;
        arr.clear();
        cin >> n; 
    }
    return 0;
}

