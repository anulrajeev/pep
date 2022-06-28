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
	vector<Node *> children;
	Node(int x)
	{
		data=x;

	}
};

Node* constructTree(vi v)
{
	stack<Node *> st;
	Node *root;
	for(int x : v)
	{
		if(x==-1)
			st.pop();
		else if(st.empty())
			{
				root=new Node(x);
				st.push(root);
			}
		else
		{
			Node *temp=new Node(x);
			(st.top()->children).push_back(temp);
			st.push(temp);
		}

	}
	return root;

}


void display(Node *root)
{
   cout<<(root->data)<<"->";
   for(Node *child : root->children)
   	  cout<<child->data<<", "; cout<<'.';
   cout<<'\n';
   for(Node *child : root->children)
   		display(child);

}

int size(Node *root)
{
	int count=0;
    for(auto child : root->children)
    	count+=size(child);
    return count+1;

}

int getMax(Node *root)
{
	int res=root->data;
	for(auto child : root->children)
		res=max(res, getMax(child));
	return res;
}

int getHeight(Node *root)
{
	int height=0;
	for(auto child  : root->children)
	{
		height=max(height, getHeight(child));
	}

	return height+1;
}

void traversal(Node *root)
{
	cout<<"Node Pre "<<root->data<<'\n';
	for(auto child : root->children)
	{
		cout<<"Edge Pre "<<root->data<<"--"<<child->data<<'\n';
		traversal(child);
		cout<<"Edge Post "<<root->data<<"--"<<child->data<<'\n';
	}
	cout<<"Node Post "<<root->data<<'\n';

}

void levelorder(Node *root)
{
	queue<Node*> q;
	q.push(root);
	while(q.size())
	{
		Node *temp=q.front(); q.pop();
		cout<<temp->data<<' ';
		for( auto child : temp->children)
			q.push(child);
	}
}


void levelorderLinewise(Node *root)
{
	queue<Node *> q;
	q.push(root);
	while(q.size())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node *temp=q.front(); q.pop();
			cout<<temp->data<<' ';
			for(auto child : temp->children)
				q.push(child);
			
		}
		cout<<'\n';
	}

}


void levelorderZigzag(Node *root)
{
	queue<Node *> q;
	stack<Node *> st1, st2;
	bool reverse=false;
	q.push(root);
	st1.push(root);
	while(st1.size() || st2.size())
	{
		
		if(!reverse)
		{
			while(st1.size())
			{
				Node *temp=st1.top(); st1.pop();
				cout<<temp->data<<' ';
				for(auto child : temp->children)
					st2.push(child);
			}
		}
		else
		{
			while(st2.size())
			{
				Node *temp=st2.top(); st2.pop();
				cout<<temp->data<<' ';
				for(auto it=temp->children.rbegin(); it!=temp->children.rend(); it++)
					st1.push(*it);
			}
		}
		reverse=!reverse;
       cout<<'\n';
	}


}

void removeLeaves(Node *root)
{
	if(root==NULL)
		return ;
	if(root->children.size()==0)
	{
		delete root;
		return;
	}
	queue<Node *> q;
	q.push(root);

	while(q.size())
	{
		Node *temp=q.front(); q.pop();
		for(int i=0;i<temp->children.size();i++)
		     if((temp->children[i])->children.size()==0)
		     	     {
		     	     	Node *t=temp->children[i];
		     	     	temp->children.erase(temp->children.begin()+i--);
		     	     	delete t;

		     	     }
		     else
		     	q.push(temp->children[i]);
	}

	display(root);
}


void mirror(Node *root)
{
	if(root==NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(q.size())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node *temp=q.front(); q.pop();
			reverse(temp->children.begin(), temp->children.end());
			for(auto child : temp->children)
				q.push(child);
		}
	}

	display(root);
}

Node *getTail(Node *root){
	if(root->children.size())
		return getTail(root->children[0]);
	return root;
}

void linearise(Node *root)
{
	for(auto child : root->children)
		linearise(child);

	while(root->children.size()>1)
	{
		vector<Node *> &v = root->children;
		Node *lc = v[v.size()-1];
		v.erase(v.begin()+v.size()-1);
		Node *sl = v[v.size()-1];
		Node *slt= getTail(sl);
		slt->children.push_back(lc); 
	}
  
}

Node* linearise2(Node *root)
{
	if(root->children.size()==0)
		return root;

    vector<Node *> &v = root->children;
	Node *lt=linearise2(v[v.size()-1]);
	while(v.size()>1)
	{
		Node *lc = v[v.size()-1];
		v.erase(v.begin()+v.size()-1);
		Node *slt=linearise2(v[v.size()-1]);
		slt->children.push_back(lc);
	}
	return lt;
}

void isPresent(Node *root, int item)
{
	if(root==NULL)
		{
 			cout<<"false";
 			return;
		}
	queue<Node *> q;
	q.push(root);
	while(q.size())
	{
		Node *temp=q.front(); q.pop();
		if(temp->data==item)
			{ cout<<"true";  return;}
		for(auto child : temp->children)
			q.push(child);
	}
	cout<<"false";

}


bool nodeToRootPath(Node* root, stack<int> &st, int item)
{
   if(root==NULL)
   	  return false;
   if(root->data == item)
   	   { 
   	   		st.push(item);
   	    	return true;
   	   } 
   	else
   	  {
   	  	  st.push(root->data);
   	  	  for(auto child : root->children)
   	  	  	if(nodeToRootPath(child, st, item))
   	  	  		return true;
   	  	  st.pop();

   	  }  
  return false;
}

void path(Node *root, int item)
{
	stack<int> st;
	if(nodeToRootPath(root, st, item))
	  {	cout<<'[';
		while(st.size()!=1)
		{
			cout<<st.top()<<", ";
			st.pop();
		}
		cout<<st.top()<<']';
	}
}

int lca(Node *root, int n1, int n2)
{
	stack<int> st1, st2;
	if(!nodeToRootPath(root, st1, n1))
			return -1;
	if(!nodeToRootPath(root, st2, n2))
			return -1;		
	int ancestor;
    stack<int> st1_new, st2_new;
    while(st1.size())
    {
    	st1_new.push(st1.top());
    	st1.pop();
    }
    while(st2.size())
    {
    	st2_new.push(st2.top());
    	st2.pop();
    }
	while(st1_new.size() && st2_new.size())
	{
		if(st1_new.top()==st2_new.top())
			ancestor=st2_new.top();
		st1_new.pop(), st2_new.pop();
	}
	return ancestor;
}

int distance(Node *root, int n1, int n2)
{
	stack<int> st1, st2;
	if(!nodeToRootPath(root, st1, n1))
			return -1;
	if(!nodeToRootPath(root, st2, n2))
			return -1;	
		// cout<<st1.top()<<'\n';
	int ancestor, count=0;
    stack<int> st1_new, st2_new;
    while(st1.size())
    {
    	st1_new.push(st1.top());
    	st1.pop();
    }
    while(st2.size())
    {
    	st2_new.push(st2.top());
    	st2.pop();
    }
	while(st1_new.size() && st2_new.size())
	{
		// cout<<st1_new.top()<<' '<<st2_new.top()<<' '<<count<<'\n';
		if(st1_new.top()==st2_new.top())
			 {
			 	ancestor=st2_new.top();
			 	count=0;
			 }
		else
			count++;
		st1_new.pop(), st2_new.pop();
		
	}
	return st1_new.size() + st2_new.size() + 2*count;
}


bool areSimilar(vi v1, vi v2)
{
	int n1 = v1.size(), n2 = v2.size();
	if(n1!=n2)
		 return false;
	for(int i=0;i<n1;i++)
		if((v1[i]!=-1 && v2[i]!=-1) || (v1[i]==-1 && v2[i]==-1))
			continue;
		else
			return false;
	return true;
}

bool areMirrors(Node *root1, Node *root2)
{
	if(root1==NULL && root2==NULL)
		 return true;
	if((root1!=NULL && root2==NULL) || (root1==NULL && root2!=NULL))
		return false;
	if(root1->children.size()!=root2->children.size())
		return false;
	int n=root1->children.size();
	for(int i=0;i<n;i++)
	{
		int j=n-1-i;
		Node *c1 = root1->children[i];
		Node *c2 = root2->children[j];
		if(!areMirrors(c1,c2))
			return false;
	}
	return true;

}

bool isSymmetric(Node *root)
{
	if(root==NULL || root->children.size()==0)
		return true;
	int n=root->children.size();
	for(int i=0;i<n/2;i++)
		if(root->children[i]->children.size() != root->children[n-1-i]->children.size())
			return false;
	for(auto child : root->children)
		if(!isSymmetric(child))
			return false;
	return true;
}


class Multisolver
{
	
	struct Node	{
			int data;
			vector<Node *> children;
			Node(int x)
			{
				data=x;

			}};
	Node* constructTree(vi v)	{
	stack<Node *> st;
	Node *root;
	for(int x : v)
	{
		if(x==-1)
			st.pop();
		else if(st.empty())
			{
				root=new Node(x);
				st.push(root);
			}
		else
		{
			Node *temp=new Node(x);
			(st.top()->children).push_back(temp);
			st.push(temp);
		}

	}
	return root;}
	public :
	int size, height, max_ele, min_ele;
	Node *root;
	
		Multisolver(vi v)
		{ size=0, height=-1, max_ele=INT_MIN, min_ele=INT_MAX, root = constructTree(v); }


		void traverse(Node *root, int level=0)
		{
			if(root==NULL)
				return;
			size++, height=max(height, level);
			max_ele=max(max_ele, root->data), min_ele=min(min_ele, root->data);
			for(auto child : root->children)
				traverse(child, level+1);
		}

		void getData()
		{
			traverse(root);
		}

};


void prnscUtil(Node *root, Node* &pre, Node* &suc, int &state, int item)
{
	if(root==NULL)
		return;
	if(state==1)
		{ suc = root; state++; }
	else if(root->data==item)
		state++;
	else if(state==0)
		pre=root;


	for(auto child : root->children)
		prnscUtil(child, pre, suc, state, item);

}

void prnsc(Node *root, Node* &pre, Node* &suc, int &state, int item)
{
	prnscUtil(root, pre, suc, state, item);
	if(state==0)
		pre=suc=NULL;
	

}



void eulerPath(Node *root, int &ceil, int &floor, int item)
{
	if(root==NULL)
		return;

	int d=root->data;
	if(d>item)
		ceil=min(ceil, d);
	if(d<item)
		floor=max(d, floor);


	for(auto child : root->children)
		eulerPath(child, ceil, floor, item);
}


int kthlargest(Node *root, int k)
{
	priority_queue<int, vector<int>, greater<int> > pq;
	queue<Node *> q;
	q.push(root);
	while(q.size())
	{
		Node *temp=q.front(); q.pop();
		if(pq.size()<k)
			pq.push(temp->data);
		else if(pq.top()<temp->data)
			{
				pq.push(temp->data);
				pq.pop();
			}
		for(auto child : temp->children)
			q.push(child);
	}
	return (pq.size()==k?pq.top():-1);
}


int eulerPath(Node *root, Node* &res_node, int &res_sum)
{
	if(root==NULL)
		return 0;
	int sum=root->data;
	for(auto child : root->children)
		sum+=eulerPath(child, res_node, res_sum);
	if(sum>res_sum)
	{
		res_sum=sum;
		res_node=root;
	}
	return sum;
}


int height(Node *root, int &diameter)
{
	if(root==NULL)
		return 0;

	int h1=0, h2=0;
	for(auto child : root->children)
		{
			int h = height(child, diameter);
			if(h>h1)
				h2=h1, h1=h;
			else if(h>h2)
				h2=h;

		}	

   diameter = max(diameter, h1+h2);
   return h1+1;
}

void iterativePreAndPostOrder(Node* root)
{
	if(root==NULL)
		return;
	stack<pair<Node *, int > > st;
	vi pre, post;
	st.push({root, -1});
	while(st.size())
	{
		Node *temp=st.top().first;
		int &d = st.top().second;

		if(d==-1)
		{
			pre.push_back(temp->data);
			d++;
		}
		else if(d==temp->children.size())
		{
			post.push_back(temp->data);
			st.pop();
		}
		else
		{
			temp=temp->children[d++];
			st.push({temp, -1});
		}


	}
	for(auto x : pre)
		cout<<x<<' ';
	cout<<'\n';
	for(auto x : post)
		cout<<x<<' ';

}
void _main()
{
  	// vi v={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
  	// sample input : 24 10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1
 	int n;
  	cin>>n;
  	vi v(n);
  	for(int i=0;i<n;i++)
  		cin>>v[i];

	Node *root=constructTree(v);
	// display(root);
	// cout<<size(root);
	// cout<<getMax(root);
	// cout<<getHeight(root)-1;
	// traversal(root);
	// levelorder(root);
	// levelorderLinewise(root);
	// levelorderZigzag(root);
	// removeLeaves(root);
	// mirror(root);
	// linearise(root); 	display(root);
	// Node *tail = linearise2(root); 	display(root);
	// int item; cin>>item; isPresent(root, item);
	// int item; cin>>item; path(root,item);
	// int n1, n2;  cin>>n1>>n2;  cout<<lca(root, n1,n2);  
	// int n1, n2;  cin>>n1>>n2;  cout<<distance(root, n1,n2);  
	// int n2; cin>>n2; vi v2(n2); for(int i=0;i<n2;i++) cin>>v2[i];  cout<<(areSimilar(v,v2)?"true":"false");
	// int n2; cin>>n2; vi v2(n2); for(int i=0;i<n2;i++) cin>>v2[i]; Node *root2 = constructTree(v2); cout<<(areMirrors(root,root2)?"true":"false");
	// cout<<(isSymmetric(root)?"true":"false");
	
	/*
		// Mulisolver
	Multisolver M(v);
	cout<<"size = "<<M.size<<"\nheight = "<<M.height<<"\nmax_element = "<<M.max_ele<<"\nmin_element = "<<M.min_ele<<"\n\n";
	M.getData();
	cout<<"size = "<<M.size<<"\nheight = "<<M.height<<"\nmax_element = "<<M.max_ele<<"\nmin_element = "<<M.min_ele<<"\n\n";
	
	*/


	/*	//------------Predecessor and Successor of an element-----------------------
	int item;
	cin>>item;
	bool found=false;
	Node *pre=NULL, *suc=NULL;
	int state = 0;
	prnsc(root,pre,suc,state, item);
	if (pre == NULL) 
    	cout << "Predecessor = Not found" << endl;
  	else 
    	cout << "Predecessor = " << pre->data << endl;
    if (suc == NULL) 
    	cout << "Successor = Not found";
    else 
    	cout << "Successor = " << suc->data;
  	*/
	/*
  			//----------ceil and floor--------------------

	int item;
	cin>>item;
	int ceil=INT_MAX, floor=INT_MIN;
	eulerPath(root, ceil, floor, item);
	cout<<"CEIL = "<<ceil<<"\nFLOOR = "<<floor;

	*/
	
	// int k; cin>>k; 	cout<<kthlargest(root, k);

	/*		//------------node with max subtree sum----------------
	Node *res_node=NULL;
	int res_sum=0;
	int sum = eulerPath(root, res_node, res_sum);
	cout<<res_node->data<<'@'<<res_sum;
	*/

	// int diameter = 0; 	int h = height(root, diameter);  	cout<<diameter;

	iterativePreAndPostOrder(root);
}

