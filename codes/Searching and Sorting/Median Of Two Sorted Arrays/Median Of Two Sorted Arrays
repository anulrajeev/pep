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

	float getMedian(vi A, vi B)
	{
		if(A.size()>B.size())
			swap(A,B);
		int n1=A.size(), n2=B.size();
		int beg=0, end=n1-1;
		while(beg<=end)
		{
			int mid1=beg+(end-beg)/2;
			int mid2=(n1+n2)/2-(mid1+1)-1;
			int l1=A[mid1],l2=B[mid2],r1=(mid1+1==n1?INT_MAX:A[mid1+1]),r2=(mid2+1==n2?INT_MAX:B[mid2+1]);
			// cout<<A[mid1]<<' '<<B[mid2]<<'\n';
			if(l1<=r2&&l2<=r1)
				return ((n1+n2)%2==0)?(max(l1,l2)+min(r1,r2))/2.0:min(r1,r2);
			else if(l1>r2)
				end=mid1-1;
			else if(l2>r1)
				beg=mid1+1;
		}

	}
	
	void _main()
	{
	  	int m;
	  	cin>>m;
	  	vector<int> A(m);
	  	for(int i=0;i<m;i++)
	  		cin>>A[i];
	  	int n;
	  	cin>>n;
	  	vector<int> B(n);
	  	for(int i=0;i<n;i++)
	  		cin>>B[i];
		float ans =getMedian(A,B);
		if(ans==int(ans))
		{
			cout<<std::fixed;
			cout<<setprecision(1)<<ans;
		}
		else
			cout<<ans;
	}
	
	