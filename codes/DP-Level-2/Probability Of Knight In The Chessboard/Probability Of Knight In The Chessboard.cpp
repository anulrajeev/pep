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

bool isValid(int x, int y, int n)
{	return x>=0&&y>=0&&x<n&&y<n; }

double findProb(int n, int k, int r, int c)
{
	vector<vector<double>>grid(n,vector<double>(n));
	grid[r][c]=1;
	int dx[]={-2,-1,1,2,2,1,-1,-2};
	int dy[]={1,2,2,1,-1,-2,-2,-1};
	while(k--)
	{
		vector<vector<double>>new_grid(n,vector<double>(n,0));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(grid[i][j])
					for(int k=0;k<8;k++)
					{
						int nx=i+dx[k], ny=j+dy[k];
						if(isValid(nx,ny,n))
							new_grid[nx][ny]+=grid[i][j]/8.0;
					}
		grid=new_grid;
	}
	double res=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			res+=grid[i][j];
	return res;
}

void _main()
{
	int n,k,r,c;
	cin>>n>>k>>r>>c;
	cout<<findProb(n,k,r,c);
}

