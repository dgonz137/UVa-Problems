#include <bits/stdc++.h>
#include <unordered_map>
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

unordered_map<int,ll> memo; //<value,#ways> (specific for coins definition)

ll change(int coins[], int money, int coin, int size){
	cout << "size: " << size << endl;
	cout << "money: " << money << " coin: " << coins[coin] << endl;
    ll ways = 0;
    //base cases
	if(money == 0) return 1;
	if(money < 0 || coin == size) {
		cout << "last coin reached !!!" << endl;
		return 0;
	}
	if(memo.count(money)) return memo.find(money)->second;
	ways += change(coins,money,coin+1,size) + change(coins,money-coins[coin],coin,size); // don't take coin & take coin
	memo[money] = ways;
	cout << "ways: " << ways << endl;
    return ways;
}
ll change(int coins[], int money){
	for(int i = 0; i < 5; i++){
		cout << "coins[" << i << "] = " << coins[i] << endl;
	}
	int size = sizeof(coins)/sizeof(coins[0]);
	cout << "size: " << size << endl;
    return change(coins,money,0,size);
}

int main(){
    FASTER;
    int coins[] = {50,25,10,5,1};
    int x;
    ll ans;
   //change(coins,30000);
    while(cin >> x){
        if(memo.count(x)) ans = memo[x];
        else ans = change(coins,x);
        if(ans == 1) cout << "There is only 1 way to produce " << x << " cents change." << endl;
        else cout << "There are " << ans << " ways to produce " << x << " cents change." << endl;
    }

    return 0;
}
