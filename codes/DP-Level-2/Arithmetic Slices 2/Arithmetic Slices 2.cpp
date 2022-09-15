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

int countAPs(int A[], int n)
{
	if(n<3)
		return 0;
	vector<unordered_map<int,int>> dp(n);

	int ans = 0;
	for(int i=1;i<n;i++)
	{
		unordered_map<int,int> &m = dp[i];
		for(int j=0;j<i;j++)
		{
			int d = A[i]-A[j];
			if(dp[j].count(d))
			{
				ans+=dp[j][d];
				m[d]+=dp[j][d]+1;
			}
			else
				m[d]++;
		}
	}
	return ans;
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	cout<<countAPs(A,n);
}

/* sample test case 

8
4 2 3 5 2 6 7 9

ans : 8

*/

