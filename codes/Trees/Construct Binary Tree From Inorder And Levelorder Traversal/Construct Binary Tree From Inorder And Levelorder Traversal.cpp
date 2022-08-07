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

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};


TreeNode* cTree(vi &in, unordered_map<int,int> &m, int is, int ie)
{
	if(is<=ie)
	{
		int ele, index=is;
		for(int i=is;i<=ie;i++)
			if(m[in[i]]<m[in[index]])
				index=i;
		
		TreeNode *temp=new TreeNode(in[index]);
		temp->left=cTree(in,m,is,index-1);
		temp->right=cTree(in,m,index+1,ie);
		return temp;
	}
	return NULL;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &levelorder)
{
	unordered_map<int,int> m;
	for(int i=0;i<levelorder.size();i++)
		m[levelorder[i]]=i;
	return cTree(inorder,m,0,inorder.size()-1);
}




void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void _main()
{
  	int n;
  	cin>>n;
  	vi in(n), levelorder(n);
  	for(int i=0;i<n;i++)
  		cin>>in[i];
  	for(int i=0;i<n;i++)
  		cin>>levelorder[i];
  	TreeNode *root = buildTree(in, levelorder);
    display(root);
}

