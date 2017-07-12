#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>   
#include <cmath>

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

bool isPerfectSquare(int x){
	int sqr = (int)round(sqrt(x));
	return sqr*sqr == x;
}

int isPalindrome(string s){
	boost::algorithm::to_lower(s);
	int i, j, k, n = s.length();
	char ss[n];
	for(i = 0, k = 0; i < n; i++) if(isalpha(s[i])) ss[k++] = s[i];
	for(i = 0, j = k-1; i < j;){
		if(!isalpha(ss[i])){i++; continue;}
		if(!isalpha(ss[j])){j--; continue;}
		if(ss[i] != ss[j]) return -1;
		i++; j--;
	}
	return k;
}

int main(){
	FASTER;
	int n, len;
	string line;
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		getline(cin, line);
		len = isPalindrome(line);
		cout << "Case #" << i << ":" << endl;
		if(len >= 0 && isPerfectSquare(len)) cout << sqrt(len) << endl;
		else cout << "No magic :(" << endl;
	}

	return 0;
}