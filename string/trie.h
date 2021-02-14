
struct node
{
	bool endMark;
	node *next[10];
	node()
	{
		endMark=false;
		for(int i=0;i<10;i++) next[i]=NULL;
	}
};

node *root;

void insert(string s)
{
	node *curr=root;
	for(char x: s)
	{
		int id=x-'0';
		if(curr->next[id]==NULL) curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endMark=true;
}

bool search(string s)
{
	node *curr=root;
	for(char x: s)
	{
		int id=x-'0';
		if(curr->next[id]==NULL) return false;
		if(curr->endMark) return true;
		curr=curr->next[id];
	}
	return false;
}

void del(node *curr)
{
	for(int i=0;i<10;i++) if(curr->next[i]) del(curr->next[i]);
	delete(curr);
}

void solve()
{
	int n;
	cin>>n;
	
	root=new node();
	
	vector<string>vec(n);
	for(string &x: vec) 
	{
		cin>>x;
		insert(x);
	}
	
	bool flag=false;
	for(string x: vec) flag|=search(x);
	
	cout<<(flag?"NO":"YES")<<"\n";
	
	del(root);
		
}		
