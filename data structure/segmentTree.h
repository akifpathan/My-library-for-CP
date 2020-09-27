
struct seg_tree
{
	vector<int>ara;
	vector<int>Tree;
	
	seg_tree(int n)
	{
		ara.resize(n+1);
		Tree.resize(4*n+1);
	}
	
	auto func(auto a,auto b)
	{
		//for sum: return a+b
		//for min: return min(a,b)
		//for max: return max(a,b)
		
	}
	
	void build(int l,int r,int at)
	{
		if(l==r)
		{
			Tree[at]=ara[l];
			return;
		}
		
		int mid=(l+r)/2;
		
		build(l,mid,at*2);
		build(mid+1,r,at*2+1);
		
		Tree[at]=func(Tree[at*2],Tree[at*2+1]);
	}
	
	//makes ara[i]=val by default, for increment use Tree[at]+=val
	void update(int l,int r,int indx,int val,int at)
	{
		if(l==r)
		{
			Tree[at]=val;
			return;
		}
		
		int mid=(l+r)/2;
		
		if(indx<=mid) update(l,mid,indx,val,at*2);
		else update(mid+1,r,indx,val,at*2+1);
		
		Tree[at]=func(Tree[at*2],Tree[at*2+1]);
	}
	
	int query(int tL,int tR,int rL,int rR,int at)
	{
		if(tL>rR || tR<rL) return ;
		//for sum return 0
		//for min return +inf
		//for max return -inf
		if(tL>=rL && tR<=rR) return Tree[at];
		
		int mid=(tL+tR)/2;
		
		int a=query(tL,mid,rL,rR,at*2);
		int b=query(mid+1,tR,rL,rR,at*2+1);
		
		return func(a,b);
	}
	
};
	
