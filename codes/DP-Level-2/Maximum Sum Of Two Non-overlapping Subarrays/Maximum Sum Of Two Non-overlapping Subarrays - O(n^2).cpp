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

void print(vvi &dp)
{
	int n = dp.size();
	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			cout<<dp[i][j]<<'\t';
		cout<<'\n';
	}
}

int maxNonOverLappingSum(int A[], int n, int x, int y)
{
	vvi dp(n,vi(n));
	for(int i=0;i<n;i++)
		dp[i][i]=A[i];
	for(int gap=1;gap<n;gap++)
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;
			dp[i][j]=dp[i][j-1]+A[j];
		}
	// print(dp);

	int res=0, len1=min(x,y), len2=max(x,y);
	int gap=len1-1;
	for(int i=0;i+gap<n;i++)
	{
		int j = i+gap;
		int A = dp[i][j];

		int gap2 = len2-1;
		for(int i2=0;i2+gap2<n;i2++)
		{
			int j2 = i2+gap2;
			int B=INT_MIN;
			if(i2<i && j2<i)
				B=dp[i2][j2];
			else if(i2>j && j2>j)
				B=dp[i2][j2];
			if(A+B>res)
			{
				// cout<<" A = "<<A<<", B = "<<B<<" res = "<<res<<'\n';
				res=A+B;
			}
		}
	}
	return res;
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	int x,y;
  	cin>>x>>y;
  	cout<<maxNonOverLappingSum(A,n,x,y);
}

