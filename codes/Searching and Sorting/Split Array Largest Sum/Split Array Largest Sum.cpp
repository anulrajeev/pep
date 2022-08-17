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


bool isFeasible(int A[], int n, int m, int maxSum)
{
	int sum=0, count=1;
	for(int i=0;i<n;i++)
		if(A[i]+sum<=maxSum)
			sum+=A[i];
		else
		{
			count++;
			sum=0;
			if(A[i]+sum<=maxSum)
				sum+=A[i];
			else
				return false;
		}
	// cout<<count<<' ';
	return (count<=m);
}

int maxSum(int A[], int n, int m)
{
	if(n<m)
		return -1;
	int beg=*max_element(A,A+n), end=accumulate(A,A+n,0), res;
	while(beg<=end)
	{
		int mid = beg+(end-beg)/2;
		// cout<<mid<<' ';
		int maxSum = mid;
		if(isFeasible(A,n,m,maxSum))
		{
			// cout<<'F';
			res=maxSum;
			end=mid-1;
		}
		else
			beg=mid+1;
		// cout<<'\n';
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
	int m;
	cin>>m;

	cout<<maxSum(A,n,m);  	

}

