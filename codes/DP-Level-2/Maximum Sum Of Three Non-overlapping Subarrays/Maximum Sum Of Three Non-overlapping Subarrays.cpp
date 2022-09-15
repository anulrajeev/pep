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

void maxSum(int A[], int n, int k)
{
	int sum=0;
	int left[n]={0}, right[n]={0};

	int prefix[n]={A[0]};
	for(int i=1;i<n;i++)
		prefix[i]=prefix[i-1]+A[i];

	for(int i=0;i<n;i++)
		if(i<=k-1)
		{
			sum+=A[i];
			left[i]=sum;
		}
		else
		{
			sum=sum+A[i]-A[i-k];
			left[i]=max(left[i-1],sum);
		}

	sum=0;
	for(int j=n-1;j>=0;j--)
		if(j>=n-k)
		{
			sum+=A[j];
			right[j]=sum;
		}
		else
		{
			sum=sum+A[j]-A[j+k];
			right[j]=max(right[j+1],sum);
		}

	int res=0;
	int midIndex, leftIndex, rightIndex;
	int rSum, lSum;
	for(int i=k;i<=n-2*k;i++)
	{
		int val = left[i-1]+ prefix[i+k-1]-prefix[i-1] +right[i+k];
		if(val>res)
		{
			res=val;
			midIndex=i;
			lSum = left[i-1], rSum = right[i+k];
		}
	}


	
	for(int i=k-1;i<midIndex;i++)
		if(prefix[i]-(i-k>=0?prefix[i-k]:0)==lSum)
			{leftIndex=i-k+1; break;}
	for(int i=midIndex+2*k-1;i<n;i++)
		if(prefix[i]-prefix[i-k]==rSum)
			{ rightIndex=i-k+1; break;}

		// cout<<rSum<<'\t';
	// for(int i=0;i<n;i++)
		// cout<<right[i]<<' ';  cout<<'\n';
	cout<<res<<' '<<leftIndex<<' '<<midIndex<<' '<<rightIndex;
}


void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	int k;
  	cin>>k;
  	maxSum(A,n,k);
}

