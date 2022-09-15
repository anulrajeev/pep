#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;

ll mod = 1000000007;

void _main();
int main(){
 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
 #endif
	_main();
	return 0;
}

int maxRevenue(int A[], int cost[], int n, int T, int index, int prev=-1, int rsf=0)
{
	if(index==n)
		return rsf;
	int res = maxRevenue(A,cost,n,T,index+1,prev,rsf);
	if(A[index]-prev>T)
		res=max(res, maxRevenue(A,cost,n,T,index+1,A[index],rsf+cost[index]));
	return res;
}

void _main()
{
  	int m,n;
  	cin>>m>>n;
  	int A[n], cost[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	for(int i=0;i<n;i++)
  		cin>>cost[i];

  	int T;
  	cin>>T;

  	cout<<maxRevenue(A,cost,n,T,0);

}

