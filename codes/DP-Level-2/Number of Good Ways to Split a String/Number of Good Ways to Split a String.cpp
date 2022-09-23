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

int goodSplits(string s)
{
	int count=0;
	unordered_map<char, int> left, right;
	for(auto x : s)
		right[x]++;
	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		left[ch]++;
		right[ch]--;
		if(right[ch]==0)
			right.erase(ch);
		count+=(left.size()==right.size());
	}
	return count;
}

void _main()
{
  	string s;
  	cin>>s;
  	cout<<goodSplits(s);
}

