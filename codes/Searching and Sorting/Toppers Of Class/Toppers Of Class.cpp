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

bool myComp(pii a, pii b)
{
	if(a.first>b.first)
		return 1;
	else if(a.first==b.first)
	{
		return a.second<b.second;
	}
	else
		return 0;
}


vi topK(int A[], int n, int k)
{
	pii student[n];
	for(int i=0;i<n;i++)
		student[i]={A[i],i};
	sort(student,student+n,myComp);
	vi res;
	for(int i=0;i<k;i++)
		res.push_back(student[i].second);
	return res;
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
	vi v = topK(A,n,k);
	for(auto x : v)
		cout<<x<<' ';
}

