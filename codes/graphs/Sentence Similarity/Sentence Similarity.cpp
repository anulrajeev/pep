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

string find(string x, unordered_map<string,string> &parent)
{
	if(x==parent[x])
		return x;
	parent[x]=find(parent[x], parent);
	return parent[x];}

void unionn(string x, string y, unordered_map<string,string> &parent, unordered_map<string,int> &rank)
{
	string x_rep = find(x,parent);
	string y_rep = find(y,parent);
	if(rank[x_rep]<rank[y_rep])
		parent[x_rep]=y_rep;
	else if(rank[y_rep]<rank[x_rep])
		parent[y_rep]=x_rep;
	else
	{
		parent[y_rep]=x_rep;
		rank[x_rep]++;
	}}


bool evaluate(vs &sentence1, vs &sentence2, vector<pair<string,string>> &similar_words)
{

	unordered_map<string,string> parent;
	unordered_map<string, int> rank;
	for(auto p : similar_words)
	{
		string s1=p.first, s2=p.second;

		if(parent.count(s1)==0)
			parent[s1]=s1, rank[s1]=0;
		if(parent.count(s2)==0)
			parent[s2]=s2, rank[s2]=0;

		if(find(s1,parent)!=find(s2,parent))
			unionn(s1,s2,parent,rank);
	}

	for(int i=0;i<sentence1.size();i++)
		if(find(sentence1[i],parent)!=find(sentence2[i],parent))
			return false;

	return true;
}

void _main()
{
  	int n;
  	cin>>n;
  	vs sentence1(n), sentence2(n);
  	for(int i=0;i<n;i++)
  		cin>>sentence1[i];
  	for(int i=0;i<n;i++)
  		cin>>sentence2[i];
  	cin>>n;
  	vector<pair<string,string>> similar_words(n);
  	for(int i=0;i<n;i++)
  		cin>>similar_words[i].first>>similar_words[i].second;
  	cout<<(evaluate(sentence1,sentence2,similar_words)?"true":"false");

}

