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


int find(int x, int parent[])
{
	if(x==parent[x])
		return x;
	parent[x]=find(parent[x],parent);
	return parent[x];
}

void unionn(int x, int y, int parent[], vi &rank)
{
	int x_rep = find(x,parent);
	int y_rep = find(y,parent);

	if(x_rep==y_rep)
		return;
	if(rank[x_rep]<rank[y_rep])
		parent[x_rep]=y_rep;
	else if(rank[y_rep]<rank[x_rep])
		parent[y_rep]=x_rep;
	else
	{
		parent[y_rep]=x_rep;
		rank[x_rep]++;
	}
}


bool isValid(int i, int j, int m, int n)
{	return (i>=0 && j>=0 && i<m && j<n); }

vi countIslands(vvi &grid, vector<pii> &points)
{
	int m=grid.size(), n=grid[0].size(), k=points.size();
	int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

	int parent[m*n];
	for(int i=0;i<m*n;i++)
		parent[i]=i;
	vi rank(m*n,0);

	int count=0;
	vi res;
	for(auto point : points)
	{
		int x=point.first, y=point.second;
		int index = x*n+y;
		grid[x][y]=1;
		count++;
		for(int k=0;k<4;k++)
		{
			int nx=x+dx[k], ny=y+dy[k];
			if(isValid(nx,ny,m,n) && grid[nx][ny])
			{
				int n_index=nx*n+ny;
				if(find(index,parent)!=find(n_index,parent))
				{
					count--;
					unionn(index,n_index,parent,rank);
				}
			}
		}
		res.push_back(count);
	}
	
	return res;
}

void _main()
{
	int m,n,k;
	cin>>m>>n>>k;
	vector<pii> points(k);
	for(int i=0;i<k;i++)  	
		cin>>points[i].first>>points[i].second;
	vvi grid(m,vi(n,0));
	vi v = countIslands(grid,points);
	
	cout<<'[';
	if(v.size())
	{
		for(int i=0;i<v.size()-1;i++)
			cout<<v[i]<<", ";
		cout<<v[v.size()-1];
	}

	cout<<']';
}

