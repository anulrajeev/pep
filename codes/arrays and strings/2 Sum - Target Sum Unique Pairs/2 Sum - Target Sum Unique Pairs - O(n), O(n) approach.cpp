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


void twoSum(int A[], int n, int sum)
{
	unordered_set<string> already_taken;
	unordered_set<int> s;

	for(int i=0;i<n;i++)
		if(s.count(sum-A[i]))
		{
			int min_ele=min(A[i],sum-A[i]), max_ele=max(A[i], sum-A[i]);

			string key=to_string(min_ele)+"_"+to_string(max_ele);
			
			if(!already_taken.count(key))
			{
				cout<<min_ele<<' '<<max_ele<<'\n';
				s.erase(sum-A[i]);
				already_taken.insert(key);
			}
		}
		else
			s.insert(A[i]);

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
  	twoSum(A,n,target);
}

