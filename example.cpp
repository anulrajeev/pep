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

void wordsCombination(string ustr, int k, string asf, int ci)
{
	if(ci==ustr.length())
	{
		if(asf.length()==k)
			cout<<asf<<'\n';
	}
	else
	{
		asf.push_back(ustr[ci]);
		wordsCombination(ustr,k,asf,ci+1);
		asf.pop_back();

		wordsCombination(ustr,k,asf,ci+1);
	}
}

void _main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	string ustr;
	int freq[26]={0};
	for(auto x : s)
		if(freq[x-'a']==0)
		{
			freq[x-'a']++;
			ustr.push_back(x);	
		}

	wordsCombination(ustr,k,"",0);
}

