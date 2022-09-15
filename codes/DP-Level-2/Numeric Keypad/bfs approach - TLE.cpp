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


ll f(int n)
{
	queue<int> q;
	unordered_map<int,vi> m;
	m[0]={0,8};
	m[1]={1,2,4};
	m[2]={1,2,3,5};
	m[3]={2,3,6};
	m[4]={1,4,5,7};
	m[5]={2,4,5,6,8};
	m[6]={3,5,6,9};
	m[7]={4,8,7};
	m[8]={0,5,7,8,9};
	m[9]={6,8,9};

	for(int i=0;i<=9;i++)
		q.push(i);
	while(--n)
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int d = q.front();	q.pop();
			for(int x : m[d])
				q.push(x);
		}
	}
	return q.size();
}

void _main()
{
  	int n;
  	cin>>n;
  	cout<<f(n);
}

