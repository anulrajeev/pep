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

int minMoves(string str)
{
	int count=0;
	queue<string> q;
	unordered_set<string> s;
	vvi possible_indices={ {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4} };
	
	q.push(str);
	s.insert(str);


	while(q.size())
	{
		int size=q.size();
		for(int t=0;t<size;t++)
		{
			str = q.front(); q.pop();
			if(str=="123450")
				return count;
			int idx=0;
			while(str[idx]!='0')
				idx++;
			for(auto index : possible_indices[idx])
			{
				swap(str[index], str[idx]);
				if(!s.count(str))
					q.push(str), s.insert(str);
				swap(str[index], str[idx]);
			}
		}
		count++;
	}
	return -1;
}

void _main()
{
  	string s(6,'.');
  	for(int i=0;i<6;i++)	
  		cin>>s[i];
  	
  	cout<<minMoves(s);

}

