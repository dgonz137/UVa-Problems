#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX(a,b) ( (a > b) ? (a) : (b) )

int N, x, T, K;
int t_favour[102];
int price[102];
int memo[102][1200][25];

int maxFavour(int k, int money, int n){
	int bill = money + (N+1)*T; // what they have spent + tea cost
	int total = ceil((double)bill*1.1L); // 10% of tax
	if(total > (N+1)*x || n > 2*(N+1)) return INT_MIN;
	if(k == K || total == (N+1)*x || n == 2*(N+1)) return 0;
	if(memo[k][money][n] != -1) return memo[k][money][n];
	return memo[k][money][n] = MAX(maxFavour(k+1,money+price[k],n+1)+t_favour[k], //don't take any
				MAX(maxFavour(k+1,money+2*price[k],n+2)+2*t_favour[k],// take 1
					maxFavour(k+1,money,n))); // take 2
									 
}

int main(){
	cin >> N >> x >> T >> K;
	while(true){
		if(!N && !x && !T && !K) break;
		for(int k = 0; k < K; k++){
			cin >> price[k];
			int sum = 0, f;
			for(int i = 0; i <= N; i++){ //includes you and friends
				cin >> f;
				sum+=f;
			}
			t_favour[k] = sum;
		}
		memset(memo,-1,sizeof(memo));
		printf("%.2lf\n",(double)maxFavour(0,0,0) / (double)(N+1));
		cin >> N >> x >> T >> K;
	}

	return 0;
}