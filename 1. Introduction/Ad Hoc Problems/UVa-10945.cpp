#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
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


bool checkPalindrome(string s){
	boost::algorithm::to_lower(s);
	for(int i = 0, j = s.length()-1; i<j ;){
		if(!isalpha(s[i])){i++; continue;}
		if(!isalpha(s[j])){j--; continue;}
		if(s[i] != s[j]) return false;
		i++; j--;
	}
	return true;
}
int main(){
	FASTER;
	string line;
	while(getline(cin, line)){
		if(line.compare("DONE") == 0) break;
		if(checkPalindrome(line)) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}

	return 0;
}
