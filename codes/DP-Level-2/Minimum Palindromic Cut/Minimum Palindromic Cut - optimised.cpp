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

bool isPalindrome(string s, int i, int j)
{
	while(i<j)
		if(s[i++]!=s[j--])
			return false;
	return true;
}

void print(vvi &grid)
{
	int n=grid.size();
	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			cout<<grid[i][j]<<' ';
		cout<<'\n';
	}

}

int minPalindromeCut(string s)
{
	int n=s.length();
	vvi dp(n,vi(n,0));
	for(int gap=1;gap<n;gap++)
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;
			if(gap==1)
				dp[i][j]=(s[i]==s[j]?0:1);
			else
			{
				if(isPalindrome(s,i,j))
					dp[i][j]=0;
				else
				{
					dp[i][j]=j-i+1;
					for(int k=i;k<=j;k++)
						if(isPalindrome(s,i,k))
							dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
				}
			}
		}	
	// print(dp);
	return dp[0][n-1];
}

void _main()
{
  	string s;
  	cin>>s;
  	cout<<minPalindromeCut(s);
}

