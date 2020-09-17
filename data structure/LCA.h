
struct edge
{
	int v;
	ll w;
};

int par[mx][22],color[mx],dis[mx],in[mx],out[mx];
ll c[mx];
vector<edge>g[mx];

struct LCA
{
	int t;
	
	void dfs(int u)
	{
		in[u]=++t;
		color[u]=1;
		for(auto it: g[u])
		{
			if(!color[it.v])
			{
				par[it.v][0]=u;
				dis[it.v]=dis[u]+1;
				c[it.v]=c[u]+it.w;
				dfs(it.v);
			}
		}
		out[u]=++t;
	}
	
	void init(int n)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<20;j++) 
			{
				par[i][j]=-1;
				color[i]=0;
				in[i]=0;
				out[i]=0;
				c[i]=0;
			}
		}
		t=0;
		dfs(1);
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<20;j++)
			{
				if(par[i][j-1]!=-1)
				{
					par[i][j]=par[par[i][j-1]][j-1];
				}
			}
		}
	}
	
	bool anc(int u,int v)
	{
		return in[u]<=in[v] && out[u]>=out[v];
	}
	
	int query(int u,int v) //find the lca of u and v
	{
		if(anc(u,v)) return u;
		if(anc(v,u)) return v;
		
		for(int i=20;i>=0;i--)
		{
			if(par[u][i]>0 && !anc(par[u][i],v)) u=par[u][i];
		}
		
		return par[u][0];
	}
	
	ll cost(int u,int v)
	{
		ll ans=c[u]+c[v]-2*c[query(u,v)];
		return ans;
	}
	
	int kth(int u,int v,int k) //find the kth node on the path from u to v
	{
		int tot=dis[u]+dis[v]-2*dis[query(u,v)];
		int temp=dis[u]-dis[query(u,v)];
		int a;
		k--;
		if(temp>=k) 
		{
			a=u;
		}
		else
		{
			a=v;
			k=tot-k;
		}
		
		for(int i=0;1<<i<=k;i++)
		{
			if(k&(1<<i)) a=par[a][i];
		}
		
		return a;
	}
} lca;
