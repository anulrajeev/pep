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
	for(int i=0;i<dp.size();i++)
	{
		for(int j=0;j<dp[0].size();j++)
			cout<<dp[i][j]<<'\t';
		cout<<'\n';
	}
}


int minAsciiSum(string s1, string s2)
{
	int m=s1.length();
	int n=s2.length();
	vvi dp(m+1,vi(n+1,0));

	dp[0][0]=0;

	for(int j=1;j<=n;j++)
		dp[0][j]=dp[0][j-1]+int(s2[j-1]);
	for(int i=1;i<=m;i++)
		dp[i][0]=dp[i-1][0]+int(s1[i-1]);

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else 
				dp[i][j]=min(dp[i][j-1]+s2[j-1], dp[i-1][j]+s1[i-1]);

	print(dp);
	cout<<'\n';	
	return dp[m][n];
}

void _main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<minAsciiSum(s1,s2);
}

