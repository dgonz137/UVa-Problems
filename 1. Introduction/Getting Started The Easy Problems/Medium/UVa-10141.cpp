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
	int reqs, props;
	string req, prop;
	vector<string> req_list;
	vector<string> prop_list;
	vector<double> price_list;
	vector<int> req_met_list;
	double price, max_req;
	int req_met;
	while(cin >> reqs >> props){
		if(!reqs) break;
		max_req = 0
		cin.ignore();
		//cout << "Requirements:" << endl;
		for(int i = 0; i < reqs; i++){
			getline(cin, req);
			//cout << "Req: " << i+1 << " = " << req << endl;
			req_list.push_back(req);
		}
		//cout << "End of requirements." << endl;
	//	cout << "Proposals:" << endl;
		for(int i = 0; i < props; i++){
			getline(cin, prop);
			prop_list.push(prop);
			//cout << "Name of proposal: " << prop << endl;
			cin >> price >> req_met;
			price_list.push_back(price);
			req_met_list.push_back(req_met);
			if(req_met > max_req) max_req = req_met;
			//cout << "Price: " << price << " and number of requirements met: " << req_met << endl;
			cin.ignore();
			for(int j = 0; j < req_met; j++){
				getline(cin, req);
				cout << "Requirement met: " << req;
			}
		}
		//cout << "List of candidates:" << endl;
		string highest_compliance_prop;
		double lowest_price_prop = (1<<31)-1;
		for(int i = 0; i < props; i++){
			if(req_met[i]==max_req){
				if(req_met_list[i] < lowest_price_prop){
					lowest_price_prop = req_met_list[i];
					highest_compliance_prop = prop_list[i];
				}
			}
		}
		cout << highest_compliance_prop << endl;
		req_list.clear();
		prop_list.clear();
		price_list.clear();
		req_met_list.clear();
		
	}

	return 0;
}