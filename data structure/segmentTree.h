
struct seg_tree
{
	vector<int>ara;
	vector<int>Tree;
	
	seg_tree(int n)
	{
		ara.resize(n+1);
		tree.resize(4*n+1);
	}
	
	void build(int l,int r,int at)
	{
		if(l==r)
		{
			tree[at]=ara[l];
			return;
		}
		
		int mid=(l+r)/2;
		
		build(l,mid,at*2);
		build(mid+1,r,at*2+1);
		
		tree[at]=tree[at*2]+tree[at*2+1];
		//tree[at]=min(tree[at*2],tree[at*2+1]);
		//tree[at]=max(tree[at*2],tree[at*2]+1);
	}
	
	int query_sum(int tL,int tR,int rL,int rR,int at)
	{
		if(tL>rR || tR<rL) return 0;
		if(tL>=rL && tR<=rR) return tree[at];
		
		int mid=(tL+tR)/2;
		
		int a=query_sum(tL,mid,rL,rR,at*2);
		int b=query_sum(mid+1,tR,rL,rR,at*2+1);
		
		return a+b;
	}
	
	int query_max(int tL,int tR,int rL,int rR,int at)
	{
		if(tL>rR || tR<rL) return -1000000000;
		if(tL>=rL && tR<=rR) return tree[at];
		
		int mid=(tL+tR)/2;
		
		int a=query_max(tL,mid,rL,rR,at*2);
		int b=query_max(mid+1,tR,rL,rR,at*2+1);
		
		return max(a,b);
	}
	
	int query_min(int tL,int tR,int rL,int rR,int at)
	{
		if(tL>rR || tR<rL) return 1000000000;
		if(tL>=rL && tR<=rR) return tree[at];
		
		int mid=(tL+tR)/2;
		
		int a=query_min(tL,mid,rL,rR,at*2);
		int b=query_min(mid+1,tR,rL,rR,at*2+1);
		
		return a+b;
	}
	
};
	
