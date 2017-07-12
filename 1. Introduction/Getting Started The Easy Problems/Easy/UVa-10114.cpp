#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(v)v.begin(),v.end()
#define PB(v)push_back(v)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

map<int,double> monthly_depr;

int solve(double curr_loan, double dp, int months){ //curr_loan is what's left to pay
	int i;
	double car_val = curr_loan + dp; //can be used to keep track of depreciation
	double monthly_payments = curr_loan / months;
	double curr_depr = monthly_depr[0];
	car_val -= (car_val*curr_depr); // 0th month depreciation
	if(curr_loan < car_val) return 0;
	for(i = 1; i <= months && car_val <= curr_loan; i++){
		if(monthly_depr.count(i)) curr_depr = monthly_depr[i];
		car_val -= (car_val*curr_depr);
		curr_loan -= monthly_payments;
	}
	return i-1;
}
int main(){
	FASTER;
	int months,depreciations,month;
	double loan,dp,depr;
	int ans;
	do{
		cin >> months >> dp >> loan >> depreciations;
		if(months <= 0) break;
		while(depreciations--){
			cin >> month >> depr;
			monthly_depr[month] = depr;
		}
		ans = solve(loan,dp,months);
		if(ans == 1) cout << "1 month" << endl;
		else cout << ans << " months" << endl;
		monthly_depr.clear();
	}while(true);

	return 0;
}
