struct DSU
{
	vector<int>par;
	
	DSU(int n)
	{
		par.resize(n+1);
		iota(par.begin(),par.end(),0);
	}
	
	int Find(int a)
	{
		return par[a]==a?a:par[a]=Find(par[a]);
	}
	
	bool same(int a,int b)
	{
		a=Find(a);
		b=Find(b);
		return a==b;
	}
	
	void Union(int a,int b)
	{
		a=Find(a);
		b=Find(b);
		
		par[b]=a;
	}
};
