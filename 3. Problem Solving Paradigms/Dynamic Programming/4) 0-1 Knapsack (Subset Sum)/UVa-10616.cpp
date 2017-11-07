#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 202

int arr[MAX];
int memo[MAX][MAX][12];
int N, Q, D, M;

int dp(int n, int sum, int m){
	if(m == M && !sum) return 1;
	if((m == M && sum) || n == N) return 0;
	if(memo[n][sum][m] != -1) return memo[n][sum][m];
	return memo[n][sum][m] = dp(n+1,sum%D,m) + dp(n+1,(sum+arr[n])%D,m+1); 
}

int main(){
	cin >> N >> Q;
	int set = 1;
	while(N && Q){
		cout << "SET " << set << ":" << endl; 
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		for(int i = 0; i < Q; i++){
			cin >> D >> M;
			memset(memo,-1,sizeof(memo));
			cout << "QUERY " << i+1 << ": " << dp(0,0,0) << endl;
		}
		cin >> N >> Q;
		set++;
	}
	return 0;
}