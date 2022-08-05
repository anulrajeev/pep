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

vi findMajority(int A[], int n, int k)
{
	unordered_map<int, int> m;
	for(int i=0;i<n;i++)
		if(m.count(A[i]))
			m[A[i]]++;
		else if(m.size()<k-1)
			m[A[i]]++;
		else
		{
			vi v;
			for(auto &p : m)
			{
				p.second--;
				if(p.second==0)
					v.push_back(p.first);
			}
			for(auto x : v)
				m.erase(x);
				
		}

	vi res;
	for(auto p : m)
	{
		int count=0;
		for(int i=0;i<n;i++)
			if(A[i]==p.first)
				count++;
		if(count>n/k)
			res.push_back(p.first);

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
  	int k;
  	cin>>k;
  	vi res = findMajority(A,n,k);
  	sort(res.begin(), res.end());
  	cout<<'[';
  	for(int i=0;i<res.size()-1;i++)
  		cout<<res[i]<<", ";
  	if(res.size())
  		cout<<res[res.size()-1];
  	cout<<']';
  	

}

