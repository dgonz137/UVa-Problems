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


int main(){
	FASTER;
	int T,n,x,max,count=1;
	cin >> T;
	while(T--){
		max = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x > max) max = x;
		}
		cout << "Case " << count++ << ": " << max << endl;
	}

	return 0;
}
