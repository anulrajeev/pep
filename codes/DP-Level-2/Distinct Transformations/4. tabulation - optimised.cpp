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

int f(string s1, string s2, int m, int n)
{
/*
	if(n==0)
		return 1;
	else if(m==0)
		return 0;
	else
	{
		int ans = f(s1,s2,m-1,n);
		if(s1[m-1]==s2[n-1])
			ans+=f(s1,s2,m-1,n-1);
		return ans;
	} 
*/
	int dp[n+1][m+1];
	for(int j=0;j<=m;j++)
		dp[0][j]=1;
	for(int i=1;i<=n;i++)
		dp[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(s2[i-1]==s1[j-1])
				dp[i][j]+=dp[i-1][j-1];
		}

	// for(int i=0;i<=n;i++)
	// {	for(int j=0;j<=m;j++)
	// 		cout<<dp[i][j]<<' ';
	// 	cout<<'\n';
	// }


	return dp[n][m];
}


void _main()
{
  	string s1,s2;
  	cin>>s1>>s2;
  	cout<<f(s1,s2,s1.length(),s2.length());
}

