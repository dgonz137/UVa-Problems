#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

vector<int> LIS(vector<int> *v, int n){
    int maxx = 1;
    int LIS[n];
    vector<int> lis;
    fill(LIS,LIS+n,1);
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if((*v)[i] < (*v)[j]) LIS[i] = MAX(LIS[i],LIS[j]+1);
        }
    }
    lis.assign(LIS,LIS+n);
    return lis;
}
vector<int> LDS(vector<int> *v, int n){
    int maxx = 1;
    int LDS[n];
    vector<int> lds;
    fill(LDS,LDS+n,1);
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if((*v)[i] > (*v)[j]) LDS[i] = MAX(LDS[i],LDS[j]+1);
        }
    }
    lds.assign(LDS,LDS+n);
    return lds;
}
int find_max(vector<int> *v){
    int n = v->size();
    if(n == 0) return 0;
    if(n == 1) return 1;
    vector<int> lis = LIS(v,n);
    vector<int> lds = LDS(v,n);
    int sum, maxx = 1;
    for(int i = 0; i < n; i++){
        sum = lis[i] + lds[i];
        if(sum > maxx)  maxx = sum;
    }
    return maxx - 1;
}
int main()
{
    int tc,n,x,ans;
    vector<int> v;
    cin >> tc;
    while(tc--){
        cin >> n;
        while(n--){
            cin >> x;
            v.push_back(x);
        }
        ans = find_max(&v);
        cout << ans << endl;
        v.clear();
    }
    return 0;
}
