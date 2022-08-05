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

int firstPositiveMissing(int A[], int n)
{
	bool found=false;	//checking the presence of 1
	for(int i=0;i<n;i++)
		if(A[i]<1 || A[i]>n)
			A[i]=1;
		else if(A[i]==1)
			found=true;

	if(found==false)
		return 1;


	for(int i=0;i<n;i++)
	{
		int ele=abs(A[i]);
		A[ele-1]=-abs(A[ele-1]);
	}
	
	for(int i=0;i<n;i++)
		if(A[i]>0)
			return i+1;

	return n+1;
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	cout<<firstPositiveMissing(A,n);

}

