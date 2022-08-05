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

char find(char ch, unordered_map<char,char> &parent)
{
	if(ch==parent[ch])
		return ch;
	parent[ch]=find(parent[ch],parent);
	return parent[ch];
}

void unionn(char x, char y, unordered_map<char,char> &parent, unordered_map<char,int> &rank)
{
	char x_rep = find(x,parent);
	char y_rep = find(y,parent);

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

bool evaluate(vs &equation)
{
	int n=equation.size();

	unordered_map<char,char> parent;
	unordered_map<char, int> rank;
	for(auto s : equation)
	{
		char ch1=s[0], ch2=s[3], oper=s[1];
		if(parent.count(ch1)==0)
			parent[ch1]=ch1, rank[ch1]=0;
		if(parent.count(ch2)==0)
			parent[ch2]=ch2, rank[ch2]=0;
		switch(oper)
		{
			case '=':
						if(find(ch1,parent)!=find(ch2,parent))
							unionn(ch1,ch2,parent,rank);
		}
	}
	for(auto s : equation)
	{
		char ch1=s[0], ch2=s[3], oper=s[1];
		if(parent.count(ch1)==0)
			parent[ch1]=ch1, rank[ch1]=0;
		if(parent.count(ch2)==0)
			parent[ch2]=ch2, rank[ch2]=0;
		switch(oper)
		{
			case '!':   if(find(ch1,parent)==find(ch2,parent))
							return false;
		}
	}


	return true;
}

void _main()
{
  	int n;
  	cin>>n;
  	vs equation(n);
  	for(int i=0;i<n;i++)
  		cin>>equation[i];
  	cout<<(evaluate(equation)?"true":"false");
}

