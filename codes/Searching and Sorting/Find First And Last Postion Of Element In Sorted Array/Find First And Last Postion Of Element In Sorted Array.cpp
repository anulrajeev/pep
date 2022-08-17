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

pii binarySearch(int A[], int n, int ele)
{
	pii res={-1,-1};
	int beg=0, end=n-1;
	while(beg<=end)
	{
		int mid = beg+(end-beg)/2;
		if(A[mid]==ele)
		{
			res.first = mid;
			end=mid-1;
		}
		else if(A[mid]<ele)
			beg=mid+1;
		else 
			end=mid-1;
	}

	beg=0, end=n-1;
	while(beg<=end)
	{
		int mid = beg+(end-beg)/2;
		if(A[mid]==ele)
		{
			res.second = mid;
			beg=mid+1;
		}
		else if(A[mid]<ele)
			beg=mid+1;
		else 
			end=mid-1;
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
  	int ele;
  	cin>>ele;
  	pii p = binarySearch(A,n,ele);
  	cout<<p.first<<' '<<p.second;
}

