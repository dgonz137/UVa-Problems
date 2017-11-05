#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MIN(a,b) ((a) < (b) ? (a) : (b)) 

// if 0<S<=300 then 0<sum_x,sum_y<=300 because we need to find the the sum given by the formula which must be exactly equal emudulus
int memo[310][310][50]; 

int numberOfCoins(vii coins, int coin, int sum_x, int sum_y, int emodulus, int size){
	int ncoins = 0;
	int money = sum_x * sum_x + sum_y * sum_y;
	if(money == emodulus){
		return 0;
	}
	if(money > emodulus || coin == size){
		return INT_MAX;
	}
	if(memo[sum_x][sum_y][coin]){ // use result. DP
		return memo[sum_x][sum_y][coin];
	}
	else{
		ncoins += MIN(numberOfCoins(coins,coin+1,sum_x,sum_y,emodulus,size), // don't take coin
				 numberOfCoins(coins,coin,sum_x+coins[coin].first,sum_y+coins[coin].second,emodulus,size)+1); // take coin	
	}
	memo[sum_x][sum_y][coin] = ncoins; //save result. DP
	return ncoins;
}

int main(){
	int T, m, S, x, y;
	cin >> T;
	int ans;
	while(T--){
		vii coins;
		cin >> m >> S;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			coins.push_back(make_pair(x,y));
		}
		memset(memo,0,sizeof(memo)); //reset memoization table. DP
		if( (ans = numberOfCoins(coins,0,0,0,S*S,coins.size())) == INT_MAX ){
			cout << "not possible" << endl;
		}
		else{
			cout << ans << endl;
		}
	}

	return 0;
}