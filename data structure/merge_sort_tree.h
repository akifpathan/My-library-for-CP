
struct merge_sort_tree
{
	int n;
	vector<int>ara;
	vector<vector<int>>Tree;
	
	merge_sort_tree(int _n)
	{
		n=_n;
		ara.resize(n+1);
		Tree.resize(4*n+1);
	}
	
	void build(int l,int r,int at)
	{
		if(l==r)
		{
			Tree[at].push_back(ara[l]);
			return;
		}
		
		int mid=(l+r)/2;
		int left=2*at;
		int right=2*at+1;
		
		build(l,mid,left);
		build(mid+1,r,right);
		
		merge(Tree[left].begin(),Tree[left].end(),Tree[right].begin(),Tree[right].end(),back_inserter(Tree[at]));
	}
	
	//number of items strictly less then k in range [rL,rR]
	//n(logn)^2
	int query(int tL,int tR,int rL,int rR,int k,int at)
	{
		if(tL>rR || tR<rL) return 0;
		if(tL>=rL && tR<=rR) return lower_bound(Tree[at].begin(),Tree[at].end(),k)-Tree[at].begin();
		
		int mid=(tL+tR)/2;
		
		int a=query(tL,mid,rL,rR,k,at*2);
		int b=query(mid+1,tR,rL,rR,k,at*2+1);
		
		return a+b;
	}
	
	//kth smallest number in the subarray [l,r]
	//(logn)^3
	int kth(int l,int r,int k)
	{
		int hi=1e9;
		int lo=-1e9;
		int ans=-2e9;
		
		while(hi>=lo)
		{
			int mid=(hi+lo)/2;
			
			if(query(1,n,l,r,mid,1)<k)
			{
				ans=mid;
				lo=mid+1;
			}
			else hi=mid-1;
		}
		
		return ans;
	}
	
};

