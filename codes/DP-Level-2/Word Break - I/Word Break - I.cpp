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

void partition(string s, int i, unordered_set<string> &dict, string asf="")
{
	if(i==s.length())
		cout<<asf<<'\n';
	else
	{
		for(int j=i;j<s.length();j++)
			if(dict.count(s.substr(i,j-i+1)))
					partition(s,j+1,dict,asf+s.substr(i,j-i+1)+" ");
	}
}

void _main()
{
	int n;
	cin>>n;
	string dictWord;
	unordered_set<string> dict;
	for(int i=0;i<n;i++)
	{
		cin>>dictWord;
		dict.insert(dictWord);
	}
	string s;
	cin>>s;
	partition(s,0,dict);
}
