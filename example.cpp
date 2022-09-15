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

int f(string text)
{
	int n=text.length();
	int dp[n];
	dp[0]=0;
	unordered_set<string> taken;

	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=i;j>=0;j--)
			{
				string s=text.substr(j,i-j+1);
				string sub=s.substr(0, s.length()/2);
				if(sub+sub==s && taken.count(s)==0)
				{
					dp[i]++;
					taken.insert(s);
				}
			}
	}

	// for(int i=0;i<n;i++)
		// cout<<dp[i]<<' ';  cout<<'\n';
	// for(int i=0;i<n;i++)
		// cout<<text[i]<<' ';  cout<<'\n';
	return dp[n-1];
}

void _main()
{
  	string s;
  	cin>>s;
  	cout<<f(s);
}

