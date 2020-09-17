
struct BIT
{
	int n;
	vector<int>bit;
	
	BIT(int _n)
	{
		n=_n;
		bit.resize(n+1);
	}
	
	void update(int indx,int val)
	{
		if(indx>0) for(;indx<=n;indx+=(indx&-indx)) bit[indx]+=val;
	}
	
	int sum(int indx)
	{
		int tot=0;
		for(;indx>0;indx-=(indx&-indx)) tot+=bit[indx];
		return tot;
	}
	
	int sum(int l,int r)
	{
		return sum(r)-sum(l-1);
	}
};
