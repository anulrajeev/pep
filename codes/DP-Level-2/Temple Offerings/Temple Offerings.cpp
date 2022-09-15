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

int minOfferings(int A[], int n)
{
	int left[n], right[n];
	left[0]=right[n-1]=1;

	for(int i=1;i<n;i++)
		if(A[i]>A[i-1])
			left[i]=left[i-1]+1;
		else
			left[i]=1;

	for(int j=n-2;j>=0;j--)
		if(A[j]>A[j+1])
			right[j]=right[j+1]+1;
		else
			right[j]=1;

	int res=0;	
	for(int i=0;i<n;i++)
		res+=max(left[i],right[i]);

	return res;
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	cout<<minOfferings(A,n);
}

