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

bool isFeasible(int weight[], int n, int D, int maxCap)
{
	int count=1, amt=0;
	for(int i=0;i<n;i++)
		if(amt+weight[i]<=maxCap)
			amt+=weight[i];
		else
		{
			count++;
			amt=0;
			if(weight[i]<=maxCap)
				amt=weight[i];
			else
				return false;
		}
	return (count<=D);
}

int maxWeightCapacity(int A[], int n, int D)
{
	int beg=*max_element(A,A+n), end=accumulate(A,A+n,0), res;
	while(beg<=end)
	{
		int mid=beg+(end-beg)/2;
		int maxCap = mid;
		if(isFeasible(A,n,D,maxCap))
			res=mid, end=mid-1;
		else
			beg=mid+1;
	}
	return res;
}

void _main()
{
	int n;
	cin>>n;
	int weight[n];
	for(int i=0;i<n;i++)
		cin>>weight[i];
	int D;
	cin>>D;
	cout<<maxWeightCapacity(weight,n,D);

}

