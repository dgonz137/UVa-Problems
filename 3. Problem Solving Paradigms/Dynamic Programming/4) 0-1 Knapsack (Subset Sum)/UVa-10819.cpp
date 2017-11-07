#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX(a,b) ((a > b) ? (a) : (b))

int dp[101][15001];
int cost[101];
int favour[101];

int maxFavour(int item, int totalCost, int budget, int size){

	if(item == size){
		if(totalCost <= budget || (totalCost > 2000 && totalCost <= budget+200)){
			return 0;
		}
		return INT_MIN;
	}
	
	int &totalFavour = dp[item][totalCost];
	
	if(totalFavour == -1){
		int other = -1;
		int increased = cost[item] + totalCost;
		if(increased <= budget+200){
			other = maxFavour(item+1,increased,budget,size)+favour[item];
		}
		totalFavour = maxFavour(item+1,totalCost,budget,size);
		if(other >= 0 || totalFavour >= 0){
			totalFavour = MAX(totalFavour,other);
		}
		
	}
	
	return totalFavour;
}

int maxFavour(int budget,int n){
	return maxFavour(0,0,budget,n);
}


int main(){
	int budget, n;
	while(cin >> budget >> n){
		for(int i = 0; i < n; i++){
			cin >> cost[i] >> favour[i];
		}
		memset(dp,-1,sizeof(dp));
		int ans;
		if(budget == 0 || n == 0) cout << "0" << endl;
		else{
			ans = maxFavour(budget,n);
			cout << ((ans == INT_MIN) ? 0 : ans) << endl;
		}
	}
	return 0;
}