//--------------------------Binary Trees---------------------------------

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
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

struct Node
{
	int data;
	Node *left, *right;

	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
	
};

Node* constructTree(vi v)
{
	Node *root;
	stack<pair<Node*, int>> st;
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		Node *temp = new Node(v[i]);
		if(st.size()==0)
			 root=temp;
		else if(v[i]==-1)
		{
			if(st.top().second==0)
			{
				st.top().first->left=NULL;
				st.top().second++;
			}

			else
			{
				st.top().first->right=NULL;
				st.pop();
			}
			continue;

		}
		else if(st.top().second==0)
			 { 
			 	st.top().first->left=temp;
			   st.top().second++;
			 }
		else
		{
			st.top().first->right = temp;
			st.pop();
		}
		st.push({temp,0});


	}
   return root;

}


void preOrder(Node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<' ';
	preOrder(root->left);
	preOrder(root->right);
}

void display(Node *root)
{
	if(root==NULL)
		return;
	if(root->left)
		cout<<root->left->data;
	else
		cout<<".";
	cout<<" __ ";
	cout<<root->data<<" __ ";
	if(root->right)
		cout<<root->right->data;
	else
		cout<<".";
	cout<<'\n';
	display(root->left);
	display(root->right);
}


int size(Node *root)
{
	if(root==NULL)
		 return 0;
	return (size(root->left)+size(root->right)+1);
}

int sum(Node* root)
{
	if(root==NULL)
		return 0;
	return sum(root->left)+sum(root->right)+root->data;
}

int maximum(Node *root)
{
	if(root==NULL)
		return 0;
	return max({root->data, maximum(root->left), maximum(root->right)});
}

int height(Node *root)
{
	if(root==NULL)
		return -1;
	return max(height(root->left), height(root->right))+1;
}

void levelOrder(Node *root)
{
	if(root==NULL)
		return;
	queue<Node *> q;
	q.push(root);
	while(q.size())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
			{
				Node *temp=q.front(); q.pop();
				cout<<temp->data<<' ';
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);

			}
		cout<<'\n';

	}
}

void iterativePrePostInTraversal(Node *root)
{
	vi pre, in, post;
	stack<pair<Node*, int> >st;
	st.push({root, 0});
	while(st.size())
	{
		Node *temp=st.top().first;
		int &state=st.top().second;
		if(state==0)
		{
			pre.push_back(temp->data);
			if(temp->left)
			  st.push({temp->left, 0});
			state++;
		}
		else if(state==1)
		{
			state++;

			in.push_back(temp->data);
			if(temp->right)
				st.push({temp->right, 0});
			

		}
		else
		{
			post.push_back(temp->data);
			st.pop();	
		}
	}

	for(auto x: pre)  cout<<x<<' '; cout<<'\n';
	for(auto x: in)  cout<<x<<' '; cout<<'\n';
	for(auto x: post)  cout<<x<<' '; cout<<'\n';
}

bool find(Node *root, int item)
{
	if(root==NULL)
		return false;
	if(root->data==item)
		return true;
	if(find(root->left, item) || find(root->right, item))
		return true;
	return false;
}


bool nodeToRootPathUtil(Node *root, int item, stack<int> &st)
{
	if(root==NULL)
		return false;
	if(root->data == item)
	{
		st.push(item);
		return true;
	}
	st.push(root->data);
	if(nodeToRootPathUtil(root->left, item, st) || nodeToRootPathUtil(root->right, item, st))
		return true;
	st.pop();
	return false;

}

void nodeToRootPath(Node *root, int item)
{
	
	stack<int> st;
	if(!nodeToRootPathUtil(root, item, st))
		return;
	vector<int> res(st.size());
	int index=st.size()-1;
	while(st.size())
	{
		res[index--]=st.top();
		st.pop();
	}
	for(auto x : res)
		cout<<x<<' ';

}

vector<int> nodeToRootPath2(Node *root, int item)
{
	vector<int> res;
	if(root==NULL)
		return res;
	if(root->data==item)
	{
		res.push_back(item);
		return res;
	}
	res = nodeToRootPath2(root->left,item);
	if(res.size())
	{
		res.push_back(root->data);
		return res;
	}
	res = nodeToRootPath2(root->right,item);
	if(res.size())
	{
		res.push_back(root->data);
		return res;
	}
	return res;
}
	
void kLevelsDown(Node* root, int k) 
{  	
  	if(root==NULL)
  		return;
  	if(k==0)
  		cout<<root->data<<'\n';
  	else{
  	kLevelsDown(root->left,k-1);
  	kLevelsDown(root->right,k-1);
  }
}


bool findNode(Node *root, int item, stack<Node*> &st)
{
	if(root==NULL)
		return false;
	if(root->data==item)
	{
		st.push(root);
		return true;
	}
	st.push(root);
	if(findNode(root->left, item,st))
		return true;
	if(findNode(root->right, item,st))
		return true;
	st.pop();
	return false;
}

void burnNode(Node *root, int item)
{
	stack<Node* >st;
	if(!findNode(root, item, st))
		return;
	
	queue<Node *>q;
	Node *temp, *prev=NULL;
	while(st.size() || q.size())
	{

		int n=q.size();
		for(int i=0;i<n;i++)
		{
			temp=q.front(); q.pop();
			cout<<temp->data<<' ';
			if(temp->left) 
				q.push(temp->left);
			if(temp->right) 
				q.push(temp->right);
		}

		if(st.size())
		{
			temp=st.top(); st.pop();
			cout<<temp->data<<" ";
			if(temp->left && temp->left!=prev)    q.push(temp->left);
			if(temp->right && temp->right!=prev)  q.push(temp->right);
			prev=temp;
		}
		cout<<'\n';
	}
	
}



void printKNodesFar(Node *root, int item, int k)
{
	stack<Node* >st;
	if(!findNode(root, item, st))
		return;
	
	queue<Node *>q;
	Node *temp, *prev=NULL;
	int level = 0;
	while((st.size() || q.size()) && level<=k )
	{

		int n=q.size();
		for(int i=0;i<n;i++)
		{
			temp=q.front(); q.pop();
			if(level==k)
				cout<<temp->data<<' ';
			if(temp->left) 
				q.push(temp->left);
			if(temp->right) 
				q.push(temp->right);
		}

		if(st.size())
		{
			temp=st.top(); st.pop();
			if(level==k)
				cout<<temp->data<<' ';			
			if(temp->left && temp->left!=prev)    q.push(temp->left);
			if(temp->right && temp->right!=prev)  q.push(temp->right);
			prev=temp;
		}
		level ++;
	}
	
}

void pathToLeafFromRoot(Node* root, string path, int sum, int lo, int hi)
{
  if(root==NULL)
  		return;
  sum+=root->data;
  path+=to_string(root->data)+" ";
  if(root->left==NULL && root->right==NULL)
  {
  	if(sum>=lo && sum<=hi)
  		cout<<path<<'\n';
  	return;
  }
  if(root->left)
  	pathToLeafFromRoot(root->left, path, sum, lo, hi);
  if(root->right)
  	pathToLeafFromRoot(root->right, path, sum, lo, hi);
}

void leftCloneTree(Node *root)
{
	if(root==NULL)
		return;
	Node *l=root->left;
	Node *temp=new Node(root->data);
	root->left=temp;
	temp->left=l;
	leftCloneTree(l);
	leftCloneTree(root->right);
}

void transBackFromLeftClonedTree(Node* root) {
  if(root==NULL)
      return;
  Node *t = root->left;
  root->left=t->left;
  delete t;
  transBackFromLeftClonedTree(root->left);
  transBackFromLeftClonedTree(root->right);  
}


void printSingleChildNodes(Node* root, Node* parent) {
  
 	if(root==NULL)
  		return;

  	if(parent && ((parent->left==NULL && parent->right!=NULL) || (parent->left!=NULL && parent->right==NULL)))
  			cout<<root->data<<'\n';	
  	printSingleChildNodes(root->left, root);
  	printSingleChildNodes(root->right, root);
}

void removeLeaves(Node *root)
{
	if(root==NULL)
		return;
	Node *temp;
	if(root->left)
	  {
	  	temp=root->left;
	  	if(temp->left==NULL && temp->right==NULL)
	  	   {
	  	   	root->left=NULL;
	  	   	delete temp;
	  	   }
	 }
	if(root->right)
	  {
	  	temp=root->right;
	  	if(temp->right==NULL && temp->left==NULL)
	  	   {
	  	   	root->right=NULL;
	  	   	delete temp;
	  	   }
	 }
	removeLeaves(root->left);
	removeLeaves(root->right);
}

int height(Node *root, int &diameter)
{
	if(root==NULL)
		return 0;
	int lh=height(root->left, diameter);
	int rh=height(root->right, diameter);
	diameter=max(diameter, lh+rh);
	return max(lh, rh)+1;
}


int subtreeSum(Node *root, int &res)
{
	if(root==NULL)
		return 0;
	int lsum = subtreeSum(root->left, res), rsum = subtreeSum(root->right, res);
	res+=abs(lsum-rsum);	
	return lsum+rsum+root->data;
}


int isBalanced(Node *root)
{
	if(root==NULL)
		return 0;
	int lh = isBalanced(root->left);
	if(lh==-1)
		return -1;
	int rh = isBalanced(root->right);
	if(rh==-1)
		return -1;
	if(abs(lh-rh)>1)
		return -1;
	return lh+rh+1;
	
}

int isBST(Node *root, int min_val, int max_val, Node* &res, int &n)
{
	if(root==NULL)
		return 0;
	if((min_val<root->data && root->data<max_val) && isBST(root->left,min_val, root->data) && isBST(root->right, root->data, max_val))
	{

		return true;
	}
	return -1;
}

void _main()
{
  	
  	// vi v ={50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
  	// 19 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

	int n;
	cin>>n;
	vi v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
    Node *root=constructTree(v);
    // display(root);
    // cout<<size(root);
    // cout<<sum(root);
    // cout<<maximum(root);
    // cout<<height(root);
    // levelOrder(root);
    // iterativePrePostInTraversal(root);
    // int item; cin>>item; cout<<find(root, item);
    // int item;  cin>>item;  nodeToRootPath(root, item);
    // int item;  cin>>item;  vi res = nodeToRootPath2(root, item); for(auto x : res) cout<<x<<' ';
    // int k; cin>>k; kLevelsDown(root, k);
    // int item,k;  cin>>item>>k;	burnNode(root, item, k);
    // int item,k;  cin>>item>>k;	printKNodesFar(root, item, k);
    // int lo, hi; 	cin>>lo>>hi; 	pathToLeafFromRoot(root, "", 0, lo, hi);
    // leftCloneTree(root);      display(root);
    // transBackFromLeftClonedTree(root);  display(root);
    // printSingleChildNodes(root, nullptr);
    // removeLeaves(root);   display(root);
    // int diameter = 0, h =height(root, diameter);  cout<<diameter;
    // int res = 0, sum = subtreeSum(root, res); cout<<res;
    // int res = isBalanced(root); cout<<(res!=-1?"true":"false");
    cout<<(isBST(root,INT_MIN,INT_MAX)?"true":"false");

}

