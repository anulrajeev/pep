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

int longestCommonSubarray(int A[], int m, int B[], int n)
{
	int dp[m+1][n+1];
	int res=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(A[i-1]==B[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				res=max(res,dp[i][j]);
			}
	return res;
}

void _main()
{
  	int m;
  	cin>>m;
  	int A[m];
  	for(int i=0;i<m;i++)
  		cin>>A[i];
  	int n;
  	cin>>n;
  	int B[n];
  	for(int i=0;i<n;i++)
  		cin>>B[i];

  	cout<<longestCommonSubarray(A,m,B,n);
}

