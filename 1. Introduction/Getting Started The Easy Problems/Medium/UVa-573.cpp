#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}


int main(){
	FASTER;
	int H,U,D,F;
	int day;
	double curr_h, drop_factor, hac, up;
	while(cin >> H >> U >> D >> F){
		if(!H) break;
		day = 1;
		curr_h = U;
		hac = U;
		drop_factor = U*F/100.0;
		up = U;
		while(hac <= H && (curr_h -= D) >= 0){
			up = ((up - drop_factor) > 0) ? (up - drop_factor) : 0;
			hac = curr_h + up;
			curr_h = hac;
			day++;
		}
		if(hac >= H) cout << "success on day " << day << endl;
		else cout << "failure on day " << day << endl;
	}

	return 0;
}