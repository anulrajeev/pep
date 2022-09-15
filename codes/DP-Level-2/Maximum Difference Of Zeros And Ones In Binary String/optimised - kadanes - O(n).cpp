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

int kadanes(int A[], int n)
{
	int res=A[0];
	int maxEnding = A[0];
	
	for(int i=1;i<n;i++)
	{
		maxEnding = max(A[i], maxEnding+A[i]);
		res = max(res, maxEnding);
	}
	return res;
}

int maxDiff(string s)
{
	int n=s.length();
	int A[n];

	for(int i=0;i<n;i++)
		A[i]=(s[i]=='0'?1:-1);
	
	int ans = kadanes(A,n);
	return (ans==0?-1:ans);
}

void _main()
{
    string s;
    cin>>s;
    cout<<maxDiff(s);
}

