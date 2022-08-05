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

void _main()
{
  	priority_queue<int,vector<int>, greater<int>> max_elements;
  	priority_queue<int> min_elements;

  	int n,x;
  	cin>>n;
  	for(int i=0;i<n;i++)
  	{
  		cin>>x;
  		if(max_elements.size()<3)
  			max_elements.push(x);
  		else
  		{
  			if(x>max_elements.top())
  				{
  					max_elements.pop();
  					max_elements.push(x);
  				}
  		}

  		if(min_elements.size()<3)
  			min_elements.push(x);
  		else
  		{
  			if(x<min_elements.top())
  				{
  					min_elements.pop();
  					min_elements.push(x);
  				}
  		}

  	}

  	vi max_v, min_v;
  	while(max_elements.size())
  	{
  		max_v.push_back(max_elements.top());
  		max_elements.pop();
  	}
  	while(min_elements.size())
  	{
  		min_v.push_back(min_elements.top());
  		min_elements.pop();
  	}

  	int res1=max_v[0]*max_v[1]*max_v[2];
  	int res2=min_v[2]*min_v[1]*max_v[2];
  	
  	cout<<max(res1,res2);

}

