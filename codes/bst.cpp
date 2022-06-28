

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

Node * insert(Node *root, int x)
{
	if(root==NULL)
		return new Node(x);
	
	if(x<root->data)
		root->left = insert(root->left, x);
	else if(x>root->data)
		root->right = insert(root->right, x);
	return root;
}


Node *constructTree(vi v)
{
	int n=v.size();
	if(n==0)
		return NULL;
	Node *root=new Node(v[0]);
	for(int i=1;i<n;i++)
		root = insert(root, v[i]);
	return root;
}

void display(Node *root)
{
	Node *temp=root;
	queue<Node *>q;
	q.push(root);
	while(q.size())
	{
		temp=q.front(); q.pop();
		if(temp->left)
			{
				cout<<temp->left->data<<' ';
				q.push(temp->left);
			}
		else
			cout<<" . ";
		cout<<" <- "<<temp->data<<" -> ";
		if(temp->right)
			{
				cout<<temp->right->data<<' ';
				q.push(temp->right);
			}
		else
			cout<<" . ";
		cout<<'\n';

	}
}

Node * constructTreeInorder(vi v, int beg, int end)
{
	if(beg<=end)
	{
		int mid = beg+(end-beg)/2;
		Node *temp=new Node(v[mid]);
		temp->left = constructTreeInorder(v,beg,mid-1);
		temp->right = constructTreeInorder(v,mid+1,end);
		return temp;
	}	
	return NULL;
}


int min(Node* root) 
{
	if(root==NULL)
		return INT_MIN;
	Node *temp=root;
	while(temp->left)
		temp=temp->left;
	return temp->data;
}

int max(Node* root) 
{
	if(root==NULL)
		return INT_MAX;
	Node *temp=root;
	while(temp->right)
		temp=temp->right;
	return temp->data;
}

int sum(Node* root) 
{
	if(root==NULL)
		return 0;
	return root->data + sum(root->left) + sum(root->right);
}


int size(Node* root) 
{
	if(root==NULL)
		return 0;
    return 1 + size(root->left) + size(root->right);
}


bool find(Node* root, int item) 
{
	if(root==NULL)
		return false;
	if(root->data==item)
		return true;
	if(item<root->data)
		return find(root->left, item);
	return find(root->right, item);
}

Node *getSuccessor(Node* root)
{
	root=root->right;
	while(root->left)
		root=root->left;
	return root;
}
Node *deleteNode(Node *root, int item)
{
	if(root==NULL)
		return NULL;
	if(item<root->data)
		root->left=deleteNode(root->left, item);
	else if(item>root->data)
		root->right=deleteNode(root->right, item);
	else
	{
		if(root->left==NULL)
		{
			Node *t=root->right;
			delete root;
			return t;
		}
		else if(root->right==NULL)
		{
			Node *t=root->left;
			delete root;
			return t;
		}
		else
		{
			Node *t=getSuccessor(root);
			root->data=t->data;
			root->right = deleteNode(root->right, t->data);
		}
	}
	return root;
}

Node *lca(Node *root, int n1, int n2)
{
	if(root==NULL)
		return 0;
	if(n1<root->data && n2<root->data)
		return lca(root->left, n1,n2);
	if(n1>root->data && n2>root->data)
		return lca(root->right, n1,n2);
	else
		return root;
}

void replacewithSum(Node *root, int &sum)
{
	if(root==NULL)
		return;
	replacewithSum(root->right, sum);
	int d = root->data;
	root->data=sum;
	sum+=d;
	replacewithSum(root->left, sum);
}

/*
void printInRange(Node *root, int d1, int d2, int &found, Node* &prev)
{
	if(root==NULL || found==2)
		return;
	// cout<<"visited : "<<root->data<<'\n';
	if(found==0)
	{
		prev=root;
		if(root->data==d1)
		 	found=1;
		else if(root->data>d1)
		{
			while()
		}
		else if(d1<root->data)
			printInRange(root->left, d1, d2, found, prev);
		else 
			printInRange(root->right, d1, d2, found, prev);
	
	}
	else
		{
			
			if(root->left!=prev)
				printInRange(root->left,d1,d2,found, prev);
			if(root->data>=d2)
			{
				if(root->data==d2)
					cout<<root->data;
				found=2;
				return;
			}
			if(found==2)
				return;

		}

	if(root->data<d2)
		cout<<root->data<<'\n';
	if(root->right!=prev)
		printInRange(root->right,d1,d2,found, prev);
	prev=root;
	
}*/

void inorder(Node *root, int d1, int d2)
{
	if(root==NULL)
		return;

	if(d1<root->data)
		inorder(root->left, d1,d2);
	if(d1<=root->data && root->data<=d2)
		cout<<root->data<<'\n';

	if(root->data<d2)
		inorder(root->right,d1,d2);
}


Node* getNextfromNormalInorder(stack<pair<Node*, int>> &st)
{
	while(st.size())
	{
		int &state=st.top().second;
		Node *temp=st.top().first;

		if(state==0)
		{
			if(temp->left)
				st.push({temp->left, 0});
			state++;
		}
		else if(state==1)
		{
			if(temp->right)
				st.push({temp->right,0});
			state++;
			return temp;
		}
		else if(state==2)
		{
			st.pop();
		}
	}
	return NULL;
}

Node* getNextfromReverseInorder(stack<pair<Node*, int>> &st)
{
	while(st.size())
	{
		int &state=st.top().second;
		Node *temp=st.top().first;

		if(state==0)
		{
			if(temp->right)
				st.push({temp->right, 0});
			state++;
		}
		else if(state==1)
		{
			if(temp->left)
				st.push({temp->left,0});
			state++;
			return temp;
		}
		else if(state==2)
		{
			st.pop();
		}
	}
	return NULL;
}


void pairSum(Node *root, int target)
{
	if(root==NULL)
		return;
	stack<pair<Node*, int>> ls, rs;
	ls.push({root, 0});
	rs.push({root, 0});
	Node *left  = getNextfromNormalInorder(ls);
	Node *right = getNextfromReverseInorder(rs); 
	while(left->data<right->data)
	{
		int sum = left->data + right->data;
		if(sum==target)
		{
			cout<<left->data<<' '<<right->data<<'\n';
			left  = getNextfromNormalInorder(ls);
			right = getNextfromReverseInorder(rs);
		}
		else if(sum<target)
			left  = getNextfromNormalInorder(ls);
		else
			right = getNextfromReverseInorder(rs);	
	}
}

void _main()
{
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    // 7 50 25 12 37 75 62 87  preorder
    // 7 12 25 37 50 62 75 87  inorder

    // 10 50 25 12 37 30 75 62 60 70 87 :
    /*
						50
					   /  \
					 25	   75
					/  \   / \
				  12   37 62  87
				  	  /	 /  \
					30	60  70

    */


    Node *root = constructTree(v);
    // Node *root = constructTreeInorder(v, 0 , v.size()-1);
    // display(root);
    // cout<<min(root)<<'\n'<<max(root)<<'\n'<<size(root)<<'\n'<<sum(root)<<'\n'<<(find(root, 20)?"true":"false");
    // root = deleteNode(root, 50); display(root);
    // int n1,n2;  cin>>n1>>n2;   cout<<lca(root,n1,n2)->data;
    // int sum=0; replacewithSum(root,sum); display(root);
    // int d1,d2,found=0;  cin>>d1>>d2; Node*prev=NULL; inorder(root, d1, d2); 



    int target; cin>>target; pairSum(root, target);



}

