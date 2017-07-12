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


int main(){
	FASTER;
	char line[100];
	char *p;
	vector<string> words;
	map<string,int> m;
	map<string,string> tracker;
	vector<string> sol;
	while(cin >> line && line[0] != '#'){
		p = strtok(line, " ");
		while(p){
			words.push_back(p);
			p = strtok(NULL, " ");
		}
	}
	
	vector<string> copy(words.begin(),words.end()); //keep a copy of the original list
	for(int i = 0; i < words.size(); i++){
		boost::algorithm::to_lower(words[i]); //convert word to lower case to add to map
		sort(words[i].begin(), words[i].end()); //sort the characters of each word in the list
		if(m.count(words[i])) m[words[i]]++; //if the word already exist in map add 1 to count
		else m[words[i]] = 1; //if word is new to map, set count to 1
		tracker[words[i]] = copy[i]; // relation between the anagram word and the original word
	}
	//traverse the map and see which words have exactly one 1 occurrence.
	for( auto it = m.begin(); it != m.end(); ++it ) if(it->second == 1) sol.push_back(tracker[it->first]);
   
    sort(sol.begin(),sol.end()); //sort solution in lexicographical order
	for(auto w : sol){
		cout << w << endl;
	}
	
	return 0;
}