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


int eD(string s1, string s2, int m, int n)
{
	vvi dp(m+1,vi(n+1));

	dp[0][0]=0;

	for(int i=1;i<=m;i++)
		dp[i][0]=i;
	for(int j=1;j<=n;j++)
		dp[0][j]=j;

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;

	return dp[m][n];
}

void _main()
{
	string s1,s2;
	cin>>s1>>s2;  	
	cout<<eD(s1,s2,s1.length(), s2.length());
}

