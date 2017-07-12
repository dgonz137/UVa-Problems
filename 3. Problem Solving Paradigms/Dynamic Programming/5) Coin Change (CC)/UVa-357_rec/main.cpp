/* Runs slower than iterative solution
 * Recursive implementation. Uses hasmap for memoization
*/

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

unordered_map<string,ll> memo; //<money-coin,#ways> (specific for coins definition)

ll change(int coins[], int money, int coin, int size){
    ll ways = 0;
    //base cases
	if(money == 0) return 1;
	if(money < 0 || coin == size) return 0;
	ostringstream oss;
	oss << money << "-" << coin;
	if(memo.count(oss.str())) return memo.find(oss.str())->second;
	ways += change(coins,money,coin+1,size) + change(coins,money-coins[coin],coin,size); // don't take coin & take coin
	memo[oss.str()] = ways;
    return ways;
}
ll change(int coins[], int money,int size){
    return change(coins,money,0,size);
}

int main(){
    FASTER;
    int coins[] = {50,25,10,5,1};
    int size = sizeof(coins) / sizeof(coins[0]);
    int x;
    ll ans;
    while(cin >> x){
        ans = change(coins,x,size);
        if(ans == 1) cout << "There is only 1 way to produce " << x << " cents change." << endl;
        else cout << "There are " << ans << " ways to produce " << x << " cents change." << endl;
    }

    return 0;
}
