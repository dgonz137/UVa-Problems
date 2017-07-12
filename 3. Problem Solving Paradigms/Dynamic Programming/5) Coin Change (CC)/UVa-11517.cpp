#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(v)v.begin(),v.end()
#define PB(v)push_back(v)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//unordered_map<string,ii> memo;
int memo_m[10100][110];
int memo_c[10100][110];

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

ii min(ii p1, ii p2){
	if(p1.first < p2.first) return p1;
	else if(p1.first > p2.first) return p2;
	else{ //they are equal. Compare second values
		if(p1.second < p2.second) return p1;
		else return p2;
	}
}

ii pay(vi *coins, int coin, int money, int item, int nc, int size){ //nc = number of coins used so far
	if(money >= item) return make_pair(money,nc); // money is enough to buy the item
	if(coin == size) return make_pair(9999999,9999999); // return big enough pair.
	/*ostringstream oss;
	oss << money << "-" << coin;
	string s = oss.str();
	if(memo.count(s)) return memo.find(s)->second;*/
	int m = memo_m[money][coin], n = memo_c[money][coin];
	if(m && n) return make_pair(m,n);
	ii p = min(pay(coins, coin+1, money+(*coins)[coin],item,nc+1,size), pay(coins, coin+1, money,item,nc,size));
	memo_m[money][coin] = (memo_m[money][coin]) ? MIN(memo_m[money][coin],p.first) : p.first;
	memo_c[money][coin] = (memo_c[money][coin]) ? MIN(memo_c[money][coin],p.second) : p.second;
	return p;
}

ii pay(vi *coins, int item){
	return pay(coins,0,0,item,0,coins->size());
}

int main(){
	FASTER;
	ofstream f;
	f.open("out.txt");
	int TC, item, n, x;
	ii sol;
	cin >> TC;
	int i = 1;
	f << "TC total number = " << TC << endl;
	while(TC--){
		cin >> item >> n;
		vi coins;
		f << "TC = " << i++ << endl;
		f << item << " " << n << endl;
		while(n--){
			cin >> x;
			f << x << " ";
			coins.push_back(x);
		}
		f << endl << endl;
		memset(memo_m,0,sizeof(memo_m[0][0])*110*10100);
		memset(memo_c,0,sizeof(memo_c[0][0])*110*10100);
		sol = pay(&coins,item);
		cout << sol.first << " " << sol.second << endl;
		//f << sol.first << " " << sol.second << endl;
		//memo.clear();
	}
	f.close();
	system("PAUSE");
	return 0;
}
