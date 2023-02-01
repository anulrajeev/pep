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

vector<pii> twoSum(int A[], int n, int sum)
{
	vector<pii> res;
	unordered_set<string> already_taken;
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		if(s.count(sum-A[i]))
			{
				int a=min(A[i],sum-A[i]), b=max(A[i],sum-A[i]);
				string x=to_string(a)+"_"+to_string(b);
				if(already_taken.count(x)==0)
				{
					already_taken.insert(x);
					res.push_back({a,b});
				}
			}
		else
			s.insert(A[i]);
	return res;
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
  	vector<pii> res = twoSum(A,n,target);
  	for(pii p : res)
  		cout<<p.first<<' '<<p.second<<'\n';

}

