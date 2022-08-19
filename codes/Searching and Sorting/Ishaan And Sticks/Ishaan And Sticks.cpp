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

pii calculateSquare(int A[], int n)
{
	int max_area=0, side=0;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[A[i]]++;
		if(m[A[i]]==4)
			if(A[i]*A[i]>max_area)
			{
				max_area=A[i]*A[i];
				side=A[i];
			}
	}
	return {max_area,m[side]/4};
}

void _main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    	cin>>A[i];
   	pii p = calculateSquare(A,n);
   	cout<<p.first<<' '<<p.second;
}

