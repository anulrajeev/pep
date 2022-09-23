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

int evaluateTrue(string s1, string s2)
{
	int n=s1.length();
	int T[n][n], F[n][n];
	memset(T,0,sizeof(T)),  memset(F,0,sizeof(F));

	for(int gap=0;gap<n;gap++)
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;

			if(gap==0)
			{
				T[i][j]=(s1[i]=='T'?1:0);
				F[i][j]=(s1[i]=='F'?1:0);
			}
			else 
			{
				T[i][j]=F[i][j]=0;
				for(int t=i+1;t<=j;t++)
				{
					char oper = s2[t-1];
			        int ltc = T[i][t-1];
			        int lfc = F[i][t-1];
			        int rtc = T[t][j];
			        int rfc = F[t][j];

					switch(oper)
					{
						case '&' : 	T[i][j] += ltc*rtc;
									F[i][j] += lfc*rtc + ltc*rfc+ lfc*rfc;
									break;

						case '|' :	T[i][j] += ltc*rfc + lfc*rtc + ltc*rtc;
									F[i][j] += lfc*rfc;
									break; 

						case '^' :	T[i][j] += ltc*rfc + lfc*rtc;
									F[i][j] += ltc*rtc + lfc*rfc;
									break;	
					}
				}
			}

		}

/*
	cout<<"  ";
	for(auto x : s1)
		cout<<x<<' '; cout<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<s1[i]<<' ';
		for(int j=0;j<n;j++)
			cout<<T[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"\n\n";


	cout<<"  ";
	for(auto x : s1)
		cout<<x<<' '; cout<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<s1[i]<<' ';	
		for(int j=0;j<n;j++)
			cout<<F[i][j]<<' ';
		cout<<'\n';
	}
*/
	return T[0][n-1];
}

void _main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<evaluateTrue(s1,s2);
}

