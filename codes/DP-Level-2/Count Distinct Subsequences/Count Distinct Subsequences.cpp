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

long long distinctSubsequences(string s)
{
	int n = s.length();
	long long dp[n+1]={1};
	unordered_map<char,int> m;
	for(int i=1;i<=n;i++)
	{
		char ch = s[i-1];
		if(m.count(ch)==0)
			dp[i]=dp[i-1]*2;
		else
			dp[i]=dp[i-1]*2-dp[m[ch]-1];
		m[ch]=i;
	}
	return dp[n]-1;
}


void _main()
{
	string s;
	cin>>s;
	cout<<distinctSubsequences(s);
}

