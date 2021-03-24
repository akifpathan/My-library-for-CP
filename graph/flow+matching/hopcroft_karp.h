
/*
 * 
 * Complexity: O(|E|*sqrt(|V|))
 * Finds maximum BPM
 * If first set contains n nodes and second set contains m nodes
 * then while adding edge(u,v) call with add_edge(u,n+v)
 * 1 based indexing is must, else assertion will fail
 * 
 */
 
struct hopcroft_karp
{
	#define NIL 0
	#define INF (1<<28)
	
	int n; ///n=number of nodes
	vector<vector<int>>g;
	vector<int>match,dist;
	
	hopcroft_karp(int _n=0) { this->init(_n); }
	
	void init(int _n)
	{
		n=_n;
		g.resize(n+1);
		match.resize(n+1);
		dist.resize(n+1);
	}
	
	/// 1 based indexing needed
	void add_edge(int u,int v)
	{
		assert(u>=1 && u<=n);
		assert(v>=1 && v<=n);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bool bfs()
	{
		queue<int>q;
		for(int i=1;i<=n;i++)
		{
			if(match[i]==NIL)
			{
				dist[i]=0;
				q.push(i);
			}
			else dist[i] = INF;
		}
		dist[NIL] = INF;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(u!=NIL)
			{
				for(int v: g[u])
				{
					if(dist[match[v]]==INF)
					{
						dist[match[v]]=dist[u]+1;
						q.push(match[v]);
					}
				}
			}
		}
		return (dist[NIL]!=INF);
	}
	bool dfs(int u)
	{
		if(u!=NIL)
		{
			for(int v: g[u])
			{
				if(dist[match[v]]==dist[u]+1)
				{
					if(dfs(match[v]))
					{
						match[v]=u;
						match[u]=v;
						return true;
					}
				}
			}
			dist[u]=INF;
			return false;
		}
		return true;
	}

	int run()
	{
		int matching = 0;
		while(bfs())
			for(int i=1; i<=n; i++)
				if(match[i]==NIL && dfs(i))
					matching++;
		return matching;
	}
	
	#undef NIL
	#undef INF
};
