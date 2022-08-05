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


void DFSRec(vector<pii> v, bool visited[], int i, int &len)
{
	if(visited[i])
		return;
	len++;
	visited[i]=true;
	DFSRec(v,visited,v[i].second,len);
}

int minSwaps(int A[], int n)
{
	int count=0;
	vector<pii> v(n);
	set<pii> s;
	for(int i=0;i<n;i++)
		s.insert({A[i],i});
	for(int i=0;i<n;i++)
	{
		pii p = *(s.begin());  s.erase(s.begin());
		int ele=p.first, old_index=p.second, actual_index=i;
		v[old_index]={ele, actual_index};
	}
	// for(auto p : v)
	// 	cout<<p.first<<' '<<p.second<<'\n';
	
	bool visited[n]={false};
	for(int i=0;i<n;i++)
		if(i==v[i].second)
			visited[i]=true;
	for(int i=0;i<n;i++)
		if(visited[i]==false)
		{
			int len=0;
			DFSRec(v,visited,i,len);
			count+=len-1;
		}

	return count;
}

void _main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	cout<<'\n'<<minSwaps(A,n);
}

