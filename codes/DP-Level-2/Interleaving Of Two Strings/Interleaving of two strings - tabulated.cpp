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

bool checkInterleave(string s1, string s2, string s3)
{
	int m=s1.length(), n=s2.length(), p=s3.length();

	if(m+n!=p)
		return false;
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		dp[i][0]=(s1.substr(0,i)==s3.substr(0,i));
	for(int j=0;j<=n;j++)
		dp[0][j]=(s2.substr(0,j)==s3.substr(0,j));

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			int k=i+j;
			dp[i][j]=0;
			if(i-1>=0 && s1[i-1]==s3[k-1])
				dp[i][j]=dp[i][j]||dp[i-1][j];
			if(j-1>=0 && s2[j-1]==s3[k-1])
				dp[i][j]=dp[i][j]||dp[i][j-1];
		}

	// for(int i=0;i<=m;i++)
	// {
	// 	for(int j=0;j<=n;j++)
	// 		cout<<dp[i][j]<<' ';
	// 	cout<<'\n';
	// }
	return dp[m][n];
}

void _main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	cout<<(checkInterleave(s1,s2,s3)?"true":"false");
}

