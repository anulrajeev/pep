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

bool dictSegementation(string s, unordered_set<string> &dict)
{
	int n=s.length();
	int dp[n]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			string substr = s.substr(j,i+1-j);
			cout<<substr<<' ';
			if(dict.count(substr))
				dp[i]+=(j-1>=0?dp[j-1]:1);
		}
		cout<<'\n';
	}

	for(int i=0;i<n;i++)
		cout<<dp[i]<<' ';  cout<<'\n';

	return dp[n-1];
}

void _main()
{
	int n;
	cin>>n;
	unordered_set<string> dict;
	string s;
	for(int i=0;i<n;i++)
		{
			cin>>s;  	
			dict.insert(s);
		}
	cin>>s;
	cout<<(dictSegementation(s, dict)?"true":"false");
}

