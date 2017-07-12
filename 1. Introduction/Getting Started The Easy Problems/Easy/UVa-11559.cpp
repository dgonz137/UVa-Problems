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
	int N, B, H, W;
	int rooms, price,min,total;
	bool h;
	while(cin >> N >> B >> H >> W){
		min= 3000000;
		for(int k = 0; k < H; k++){
			cin >> price;
			h = false;
			for(int i = 0; i < W; i++){
				cin >> rooms;
				if(rooms >= N) h = true;
			}
			if(h && price < min) min = price;
		}
		if((total = min*N) <= B) cout << total << endl;
		else cout << "stay home" << endl;
	}

	return 0;
}
