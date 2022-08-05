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


bool isValid(int i, int j, int m, int n)
{	return (i>=0&&j>=0&&i<m&&j<n); 	}


int find(int x, vi &parent)
{
	if(x==parent[x])
		return x;
	parent[x]=find(parent[x],parent);
	return parent[x];
}

void unionn(int x, int y, vi &parent, vi &rank)
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

/*

##initially all are water

##for every point, make it an island, increase the count

## for every neighboring point
		check if it is valid
		check if it is island
		check if it is a disjoint island
				if all the above are true, merge the current one with the neighbouring
				count decreases.


*/

vi getIslandCount(vector<pii> &point,int m, int n)
{
	vi res;
	int count=0;
	vi parent(m*n, -1), rank(m*n,0);

	int dx[]={-1,1,0,0};
	int dy[]={0,0,-1,1};

	for(auto p : point)
	{
		int index = p.first*n+p.second;
		
		if(parent[index]!=-1)
			res.push_back(count);
		else
		{
			parent[index]=index;
			count++;

			for(int i=0;i<4;i++)
			{
				int nx=p.first+dx[i], ny=p.second+dy[i];
				int n_index = nx*n+ny;
				if(isValid(nx,ny,m,n) && parent[n_index]!=-1)
				{
					if(find(n_index,parent)!=find(index,parent))
					{
						count--;
						unionn(index,n_index,parent,rank);
					}
				}
			}
			
			res.push_back(count);
		}
		


	}

	return res;
}

void _main()
{
  	int m,n,t;
  	cin>>m>>n>>t;
  	int x,y;
  	vector<pii> point;
  	while(t--)
  	{
  		cin>>x>>y;
  		point.push_back({x,y});
  	}
  	
  	vi v = getIslandCount(point,m,n);

  	cout<<'[';
  	for(int i=0;i<v.size()-1;i++)
  		cout<<v[i]<<", ";
  	if(v.size())
  		cout<<v[v.size()-1];
  	cout<<']';
}

