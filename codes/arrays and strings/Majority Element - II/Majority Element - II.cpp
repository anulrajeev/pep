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

pii findMajority(int A[], int n)
{
	int res1=INT_MAX, res2=INT_MAX, count1=0, count2=0;
	for(int i=0;i<n;i++)
		if(A[i]==res1)
			count1++;
		else if(A[i]==res2)
			count2++;
		else if(count1==0)
			res1=A[i],count1++;
		else if(count2==0)
			res2=A[i], count2++;
		else
			count1--, count2--;
	
	count1=count2=0;
	for(int i=0;i<n;i++)
		if(A[i]==res1)
			count1++;
		else if(A[i]==res2)
			count2++;
	if(count1<=n/3)
		res1=INT_MAX;
	if(count2<=n/3)
		res2=INT_MAX;
	return {min(res1,res2),max(res1,res2)};

}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	pii res = findMajority(A,n);

  	cout<<'[';
  	if(res.first!=INT_MAX)
  		cout<<res.first;
  	if(res.second!=INT_MAX)
  		cout<<", "<<res.second;
  	cout<<']';

}

