#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX(a,b) ((a) > (b) ? (a) : (b))

ll LIS(vi &h, vi &w, int n){
	vector<ll> lis(w.begin(),w.end());
	ll max = w[0];
	for(int i = 1; i < n; i++){
		for(int j = i-1; j >= 0; j--){
			if(h[i] > h[j]) lis[i] = MAX(lis[i], w[i] + lis[j]);
			if(lis[i] > max) max = lis[i];
		}
	}
	return max;
}

ll LDS(vi &h, vi &w, int n){
	vector<ll> lds(w.begin(),w.end());
	ll max = w[0];
	for(int i = 1; i < n; i++){
		for(int j = i-1; j >= 0; j--){
			if(h[i] < h[j]) lds[i] = MAX(lds[i], w[i] + lds[j]);
			if(lds[i] > max) max = lds[i];
		}
	}
	return max;
}

int main(){
	int T, n;
	cin >> T;
	for(int k = 1; k <= T; k++){
		cin >> n;
		vi h(n), w(n);
		for(int i = 0; i < n; i++){
			cin >> h[i];
		}
		for(int i = 0; i < n; i++){
			cin >> w[i];
		}
		ll lis, lds;
		if( (lis = LIS(h,w,n)) >= (lds = LDS(h,w,n)) ){
			cout << "Case " << k << ". Increasing (" << lis << "). Decreasing (" << lds << ")." << endl;
		}
		else{
			cout << "Case " << k << ". Decreasing (" << lds << "). Increasing (" << lis << ")." << endl;
		}
	}

	return 0;
}