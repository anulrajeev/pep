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

double findWater(int k, int r, int c)
{
	vector<vector<double>> dp(k+1,vector<double>(k+1,0));
	dp[0][0]=k;
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			if(dp[i][j]>1)
			{
				double spare = (dp[i][j]-1)/2.0;
				dp[i][j]=1;
				dp[i+1][j]+=spare;
				dp[i+1][j+1]+=spare;
			}
	return dp[r][c];
}

void _main()
{
  	int k,r,c;
  	cin>>k>>r>>c;
  	double ans = findWater(k,r,c);
  	if(ans==1)
  		cout<<fixed<<setprecision(1)<<1.0;
  	else
  		cout<<ans;
}

