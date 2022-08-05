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

vs findPattern(vs &words, string &pattern)
{
	vs res;
	for(auto word : words)
	{
		if(word.length()!=pattern.length())
				continue;

		unordered_map<char,char> w,p;
	    bool eligible=true;
		for(int i=0;i<word.length();i++)		
			if(w.count(word[i])==0 && p.count(pattern[i])==0)
			{
				w[word[i]]=pattern[i];
				p[pattern[i]]=word[i];
			}
			else
			{
				if(w.count(word[i]))
					{
						if(w[word[i]]!=pattern[i])
							{eligible=false; break;}
					}
			 	if(p.count(pattern[i]))
					{
						if(p[pattern[i]]!=word[i])
							{eligible=false; break;}
					}
			}
		if(eligible)
			res.push_back(word);
	}
	return res;
}

void _main()
{
	string pattern;
	cin>>pattern;
	int n;
	cin>>n;
	vs word(n);
	for(int i=0;i<n;i++)
		cin>>word[i]; 
	vs res = findPattern(word,pattern);
	sort(res.begin(), res.end());
	if(res.size()==0)
	    cout<<"Empty";
	else
		for(string x : res)
			cout<<x<<' ';
}

