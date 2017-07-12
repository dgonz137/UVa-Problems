#include <bits/stdc++.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

vector<int> A, LIS, R, T;

int lis(){
    int n = A.size();
    int len = 0;
    LIS.assign(n,0);
    R.assign(n,-1);
    T.assign(n,0);
    for(int i = 0; i < n; i++){
    	int pos = lower_bound(LIS.begin(),LIS.begin()+len,A[i]) - LIS.begin();
    	T[pos] = i;
    	LIS[pos] = A[i];
    	R[i] = pos ? T[pos - 1] : -1;
    	if(pos+1 > len) len = pos+1;
    }
    return len;
}

int main() {
	int x,len;
	stack<int> sol;
	while(cin >> x){
		A.push_back(x);
	}
	len = lis();
	cout << len << endl << '-' << endl;
	int index = T[len-1];
	while(index != -1){
		sol.push(A[index]);
		index = R[index];
	}
	while(!sol.empty()){
		cout << sol.top() << endl;
		sol.pop();
	}
	return 0;
}
