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


void twoSum(int A[], int beg, int end, int target)
{
	int index=beg-1;
	while(beg<end)
	{
		int sum=A[beg]+A[end];

		if(beg!=index+1 && A[beg]==A[beg-1])
			{beg++; continue;}

		if(sum==target)
		{
			cout<<A[index]<<' '<<A[beg]<<' '<<A[end]<<'\n';
			beg++, end--;
		}
		else if(sum<target)
			beg++;
		else
			end--;	

	}
}



void threeSum(int A[], int n, int target)
{
	sort(A,A+n);
	for(int i=0;i<n;i++)
		if(i!=0 && A[i]==A[i-1])
			continue;
		else
			twoSum(A,i+1,n-1,target-A[i]);
}


void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	int target;
  	cin>>target;
  	threeSum(A,n,target);

}

