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

int lcs(string s1, string s2, int m, int n)
{
	/*
	if(m==0)
		return 0;
	if(n==0)
		return 0;
	if(s1[m-1]==s2[n-1])
		return lcs(s1,s2,m-1,n-1)+1;
	else
		return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
	*/
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=n;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	return dp[m][n];

}

int minInsertions(string s)
{
	int n=s.length();
	string s2=s;
	reverse(s2.begin(),s2.end());
	int len = lcs(s,s2,n,n);
	return n-len;
}

void _main()
{
  	string s;
  	cin>>s;
  	cout<<minInsertions(s);
}

