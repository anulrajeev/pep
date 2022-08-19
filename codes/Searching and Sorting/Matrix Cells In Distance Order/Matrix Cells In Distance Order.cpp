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

bool isValid(int x, int y, int m, int n)
{	return x>=0 && x<m && y>=0 && y<n; }

vvi getDistance(int m, int n, int i, int j)
{
	unordered_map<int,set<int>> mp;
	queue<int> q;
	unordered_set<int> vis;
	q.push(i*n+j);
	vis.insert(i*n+j);
	int d=0;
	int dx[]={0,0,-1,1};
	int dy[]={-1,1,0,0};
	while(q.size())
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int index = q.front(); q.pop();
			mp[d].insert(index);
			int x=index/n, y=index%n;
			// cout<<x<<' '<<y<<"	-- > ";
			for(int k=0;k<4;k++)
			{
				int nx=x+dx[k], ny=y+dy[k];
				int n_index=nx*n+ny;
				if(isValid(nx,ny,m,n) && vis.count(n_index)==0)
				{
					// cout<<nx<<','<<ny<<"  ";
					q.push(n_index);
					vis.insert(n_index);
				}
			}
			// cout<<'\n';
		}
		// cout<<'\n';			
		d++;
	}

	vvi res(m+n);
	for(auto item : mp)
	{
		// cout<<item.first<<" ---> ";
		for(auto x : item.second)	
			res[item.first].push_back(x);
			// cout<<x<<' ';
		// cout<<'\n';
	}
	return res;
}

void _main()
{
  	int m,n,i,j;
  	cin>>m>>n>>i>>j;
  	vvi res = getDistance(m,n,i,j);
  	for(auto v : res)
  		for(auto x : v)
  				cout<<'('<<x/n<<", "<<x%n<<"), ";
}

