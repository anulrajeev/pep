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


void twoSum(int A[], int beg, int end, int target, int k, vector<int> &v)
{
	int start=beg;
	while(beg<end)
	{
		int sum=A[beg]+A[end];

		if(beg!=start && A[beg]==A[beg-1])
			{beg++; continue;}

		if(sum==target)
		{
			for(int i=0;i<v.size();i++)
				cout<<v[i]<<' ';  cout<<A[beg]<<' '<<A[end]<<'\n';
			beg++, end--;
		}
		else if(sum<target)
			beg++;
		else
			end--;	

	}
}



void KSum(int A[], int beg, int end, int target, int k, vector<int> &v)
{
	if(k==2)
		twoSum(A,beg,end,target,k,v);
	else
	{
		for(int i=beg;i<=end;i++)
			if(i!=beg && A[i]==A[i-1])
				continue;
			else if(target-A[i]>=0)
			{
				v.push_back(A[i]);
				KSum(A,i+1,end,target-A[i],k-1,v);
				v.pop_back();
			}

	}
}


void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	int target,k;
  	cin>>target>>k;
  	sort(A,A+n);
  	vector<int> v;
  	KSum(A,0,n-1,target,k,v);

}

