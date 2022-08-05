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

int f(int A[], int n)
{
	sort(A,A+n);
	long long ans=0;
	long long power[n]={1};
	for(int i=1;i<n;i++)
	{
		power[i]=(power[i-1]*2)%mod;
		cout<<power[i]<<'\n';
	}

	for(int i=0;i<n;i++)
		ans=( ans + (power[i]-power[n-i-1] )*A[i] )%mod;
	return (int)ans;

}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	cout<<f(A,n);

}

