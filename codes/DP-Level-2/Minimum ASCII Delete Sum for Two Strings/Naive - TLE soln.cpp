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


void print(vvi dp)
{
	for(int i=0;i<dp.size();i++)
	{
		for(int j=0;j<dp[0].size();j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}
}

vvi lcs(string s1, string s2)
{
	int m=s1.length(), n=s2.length();
	vvi dp(m+1,vi(n+1,0));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	return dp;	
}

void getLCS(vvi &dp, string s1, string s2, int i, int j, string s, vs &res)
{
	if(i==0 || j==0)
		res.push_back(s);
	else
	{
	   if(s1[i-1]==s2[j-1])
		{
			s.push_back(s1[i-1]);
			getLCS(dp,s1,s2,i-1,j-1,s,res);
		}
		else if(dp[i-1][j]>dp[i][j-1])
			getLCS(dp,s1,s2,i-1,j,s,res);
		else if(dp[i-1][j]>dp[i][j-1])
			getLCS(dp,s1,s2,i,j-1,s,res);
		else
		{
			if(i-1==0 && j-1==0)
				getLCS(dp,s1,s2,i-1,j,s,res);
			else
			{
				getLCS(dp,s1,s2,i-1,j,s,res);
				getLCS(dp,s1,s2,i,j-1,s,res);
			}
		}		
	}
}

int getASCII(string s)
{
	int res=0;
	for(auto x : s)
		res+=int(x);
	return res;
}

int lowestASCIIsum(string s1, string s2)
{
	vvi dp = lcs(s1,s2);
	vs res;
	string lcs;
	int maxASCII=0;
	getLCS(dp,s1,s2,s1.length(),s2.length(),"",res);
	for(auto s :res)
	{
		reverse(s.begin(),s.end());
		int ascii = getASCII(s);
		cout<<s<<" - "<<ascii<<'\n';
		if(ascii > maxASCII)
			lcs=s, maxASCII=ascii;
	}
	
	int sum=0;
	int index=0;
	for(auto x : s1)
		if(x==lcs[index])
			index++;
		else
			sum+=int(x);
	index=0;
	for(auto x : s2)
		if(x==lcs[index])
			index++;
		else
			sum+=int(x);
	return sum;
}

void _main()
{
  	string s1,s2;
  	cin>>s1>>s2;
  	cout<<lowestASCIIsum(s1,s2);
}

