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

int dp[1001][1001];

int maxSum(int A[], int n, int index, int m, int k, int prefix[])
{
	if(m==0)
		return 0;
	if(index==n)
		return 0;
	if(dp[index][m]!=-1)
		return dp[index][m];
	int exclude = maxSum(A,n,index+1,m,k,prefix);
	int include = 0;

	if(index+k-1<n)
		include = prefix[index+k-1]-(index==0?0:prefix[index-1]) + maxSum(A,n,index+k,m-1,k,prefix);

	return dp[index][m]=max(include, exclude);
}

int solution(int A[], int n, int m, int k)
{
	int prefix[n]={A[0]};
	for(int i=1;i<n;i++)
		prefix[i]+=prefix[i-1]+A[i];
	memset(dp,-1,sizeof(dp));
	return maxSum(A,n,0,m,k,prefix);
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	int m,k;
  	cin>>m>>k;
  	cout<<solution(A,n,m,k);
}

