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

int find(int x, int parent[])
{
	if(x==parent[x])
		return x;
	parent[x]=find(parent[x], parent);
	return parent[x];
}

void unionn(int x, int y, int parent[], vi &rank)
{
	int x_rep = find(x, parent);
	int y_rep = find(y, parent);

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



vvi matrixRankTransform(vvi &grid)
{
	int m=grid.size(), n=grid[0].size();
	vvi ans(m,vi(n,0));

// part 1 
	int parent[m*n];
	vi rank(m*n, 0);

	for(int i=0;i<m*n;i++)
		parent[i]=i;


// part 2

	//row union
	for(int i=0;i<m;i++)
	{
		unordered_map<int,int> mp;
		for(int j=0;j<n;j++)
		{
			int index = i*n+j;
			if(mp.count(grid[i][j]))
				unionn(index, mp[grid[i][j]], parent, rank);
			else
				mp[grid[i][j]]=index;
		}
	}

	//col union
	for(int j=0;j<n;j++)
	{
		unordered_map<int,int> mp;
		for(int i=0;i<m;i++)
		{
			int index = i*n+j;
			int ele   = grid[i][j];
			if(mp.count(ele))
				unionn(index, mp[ele], parent, rank);
			else
				mp[ele]=index;
		}
	}

// part 3

	vi v[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			int index = i*n+j;
			int rep   = find(index, parent);
			int rep_i = rep/n, rep_j = rep%n;

			v[rep_i][rep_j].push_back(index);
		}

																								/*
	for(int i=0;i<m;i++)
	{

		for(int j=0;j<n;j++)
			{
				cout<<i<<' '<<j<<" --> ";
				for(auto x : v[i][j])
					cout<<'('<<x/n<<", "<<x%n<<") ";
				cout<<'\n';
			}
	} */	
// part 4

	map<int, vvi> mp;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(v[i][j].size())
				mp[grid[i][j]].push_back(v[i][j]);

//part 5

	vi row(m, 0), col(n, 0);
	for(auto item : mp)
	{
		int ele = item.first;
		auto collection = item.second;

		for(auto v : collection)
		{
			int x = 0; //collection rank

			for(auto index : v)
			{
				int i=index/n, j=index%n;
				int curr_rank = max(row[i], col[j])+1;
				x = max(x, curr_rank);
			}

			for(auto index : v)
			{
				int i=index/n, j=index%n;
				ans[i][j] = x;
				row[i]=col[j]=x;
			}

		}
	}

	return ans;
}

void _main()
{
  	int m,n;
  	cin>>m>>n;
  	vvi grid(m,vi(n,0));
  	for(int i=0;i<m;i++)
  		for(int j=0;j<n;j++)
  			cin>>grid[i][j];

  	vvi rank = matrixRankTransform(grid);

  	// cout<<"\n\n\n";
  	for(int i=0;i<m;i++)
  	{
  		for(int j=0;j<n;j++)
  			cout<<rank[i][j]<<' ';
  		cout<<'\n';
  	}

}

