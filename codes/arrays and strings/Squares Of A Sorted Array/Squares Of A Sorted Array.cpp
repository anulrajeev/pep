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

vi convert(int A[], int n)
{
	vi res;
	int beg,mid,end;
	for(mid=0;mid<n;mid++)
		if(A[mid]>=0)
			break;
	end=mid;
	beg=mid-1;
	while(beg>=0 || end<n)
	{
		if(beg>=0)
		{
			if(abs(A[beg])<abs(A[end]))
			{
				res.push_back(A[beg]*A[beg]);
				beg--;
			}
			else
			{
				res.push_back(A[end]*A[end]);
				end++;
			}
		}
		else
			{
				res.push_back(A[end]*A[end]);
				end++;
			}

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
	vi v = convert(A,n);
	for(int i=0;i<n;i++)
		cout<<v[i]<<' ';
}

