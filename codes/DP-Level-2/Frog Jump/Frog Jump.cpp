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

bool f(unordered_set<int> &s, int A[], int n)
{
	/*
	if(pos==dest)
		return true;
	bool ans = false;
	if(pos+k-1<=dest && k-1>0 && s.count(pos+k-1))
		ans = ans || f(s,pos+k-1,dest,k-1);
	if(pos+k<=dest && s.count(pos+k))
		ans = ans || f(s,pos+k,dest,k);
	if(pos+k+1<=dest && s.count(pos+k+1))
		ans = ans || f(s,pos+k+1,dest,k+1);
	return ans;
	*/

	int dp[n][n];
	memset(dp,0,sizeof(dp));
	dp[0][0]=dp[1][1]=1;
	int dest = A[n-1];

	unordered_map<int,int> index;
	for(int i=0;i<n;i++)
		index[A[i]]=i;

	for(int j=1;j<n;j++)
		for(int i=0;i<n;i++)
			if(dp[i][j])
				{
					int pos = A[j], k=i;
					if(pos+k-1<=dest && k-1>0 && s.count(pos+k-1))
						dp[k-1][index[pos+k-1]]=1;
					if(pos+k<=dest && s.count(pos+k))
						dp[k][index[pos+k]]=1;
					if(pos+k+1<=dest && s.count(pos+k+1))
						dp[k+1][index[pos+k+1]]=1;
				}
	
	int ans = 0;
	for(int i=0;i<n;i++)
		ans|=dp[i][n-1];

	cout<<"  ";
	for(int j=0;j<n;j++)
		cout<<A[j]<<' ';  cout<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<i<<' ';
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}

	return ans;
}

bool checkJumps(int A[], int n)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(A[i]);
	if(s.count(A[0]+1)==0)
		return false;
	return f(s,A,n);
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	cout<<(checkJumps(A,n)?"true":"false");
}

