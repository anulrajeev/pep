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

vvi dp(1001, vi(1001, -1));

int minCostDeletion(string s1, string s2, int m, int n, int x, int y)
{
	if(m==0)
		return y*n;
	if(n==0)
		return x*m;
	if(dp[m][n]!=-1)
		return dp[m][n];
	if(s1[m-1]==s2[n-1])
		return dp[m][n] = minCostDeletion(s1,s2,m-1,n-1,x,y);
	else
		return dp[m][n] = min(minCostDeletion(s1,s2,m-1,n,x,y)+x,minCostDeletion(s1,s2,m,n-1,x,y)+y);
}

void _main()
{
  	string s1,s2;
  	int x,y;
  	cin>>s1>>s2>>x>>y;
  	cout<<minCostDeletion(s1,s2,s1.length(),s2.length(),x,y);
}

