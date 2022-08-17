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


void merge(int A[], int l, int mid, int r, int &count)
{
	int n1=mid-l+1, n2=r-mid;
	int L[n1], R[n2];
	for(int i=0;i<n1;i++)
		L[i]=A[l+i];
	for(int j=0;j<n2;j++)
		R[j]=A[mid+1+j];
	int i=0,j=0,k=l;
	for(;i<n1&&j<n2;)
		if(L[i]<=R[j])
			A[k++]=L[i++];
		else 
		{
			A[k++]=R[j++];
			count+=n1-i;
		}
	while(i<n1)
		A[k++]=L[i++];
	while(j<n2)
		A[k++]=R[j++];

}



void mergeSort(int A[], int l, int r, int &count)
{
	if(l<r)
	{
		int mid = l+(r-l)/2;
		// cout<<"l = "<<l<<"   mid = "<<mid<<"  r = "<<r<<'\n';
		mergeSort(A,l,mid,count);
		mergeSort(A,mid+1,r,count);
		merge(A,l,mid,r,count);
	}
}


int countInversions(int A[], int n)
{
	int count=0;
	mergeSort(A,0,n-1,count);
	return count;	
}

void _main()
{
  	int n;
  	cin>>n;
  	int A[n];
  	for(int i=0;i<n;i++)
  		cin>>A[i];
  	cout<<countInversions(A,n);
}

