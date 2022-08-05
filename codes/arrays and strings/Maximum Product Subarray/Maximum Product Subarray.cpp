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

ll mod = 1000000009;

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

int maxProduct(int A[], int n)
{
	int res=0;
	int maxEnding=1, minEnding=1;
	for(int i=0;i<n;i++)
	{	
		int new_maxEnding=max({A[i], A[i]*maxEnding, A[i]*minEnding});
		int new_minEnding=min({A[i], A[i]*maxEnding, A[i]*minEnding});
		cout<<new_maxEnding<<' '<<new_minEnding<<'\n';
		maxEnding=new_maxEnding, minEnding=new_minEnding;
		res=max(res,maxEnding);
	}
	return res;
}

void _main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	cout<<maxProduct(A,n); 	
}

/*

6
2 3 -4 -5 6 1
		max		min
2		 2		 2
3		 6		 3
-4		-4		-24
-5      120     -5
6		720		-30
1		720		-30
*/