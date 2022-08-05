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

string manipulate(string s)
{
	int n=s.length();
	queue<int> q;
	for(int i=0;i<n;i++)
		if(s[i]!='.')
			q.push(i);
	while(q.size())
	{
		unordered_set<int> locally_changed;
		int size=q.size();
		for(int i=0;i<size;i++)
		{
			int index=q.front();  q.pop();
			switch(s[index])
			{
				case 'L':
							if(index-1>=0)
								if(s[index-1]=='.')
								{
									s[index-1]='L';
									q.push(index-1);
									locally_changed.insert(index-1);
								}
								else if(s[index-1]=='R')
								{
									if(locally_changed.count(index-1))
										s[index-1]='.';
								}

							break;
				case 'R':
							if(index+1<n)
								if(s[index+1]=='.')
								{
									s[index+1]='R';
									q.push(index+1);
									locally_changed.insert(index+1);
								}
								else if(s[index+1]=='L')
								{
									if(locally_changed.count(index+1))
										s[index+1]='.';
								}

			}
		}
	}
	return s;
}

void _main()
{
  	string s;
  	cin>>s;
  	cout<<manipulate(s);

}

