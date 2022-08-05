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


void twoSum(int A[], int n, int target)
{
	sort(A,A+n);
	int left=0, right=n-1;
	unordered_set<string> already_taken;

	while(left<right)
	{
		int sum=A[left]+A[right];
		if(sum==target)
			{
				string x = to_string(A[left])+"_"+to_string(A[right]);
				
				if(!already_taken.count(x))
				{
					cout<<A[left]<<' '<<A[right]<<'\n';
					already_taken.insert(x);
				}

				left++, right--;
			}	
		else if(sum<target)
			left++;
		else
			right--;
	}

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

