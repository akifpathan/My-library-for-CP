
//nlogn for build
//logn per query
//be-careful, it uses coordinate compression

const int mx=1e5+5;

int ara[mx],rm[mx];
set<int>S;
map<int,int>M;

struct wavelet_tree
{
	int lo,hi;
	wavelet_tree *l,*r;
	vector<int>b;
	vector<ll>c;
	
	wavelet_tree(int *from,int *to,int x,int y)
	{
		lo=x;
		hi=y;
		if(from>=to) return;
		if(hi==lo)
		{
			b.reserve(to-from+1);
			b.push_back(0);
			c.reserve(to-from+1);
			c.push_back(0);
			for(auto it=from;it!=to;it++)
			{
				b.push_back(b.back()+1);
				c.push_back(c.back()+rm[*it]);
			}
			return;
		}
		
		int mid=(hi+lo)/2;
		auto f=[mid](int x) { return x<=mid; };
		b.reserve(to-from+1);
		b.push_back(0);
		c.reserve(to-from+1);
		c.push_back(0);
		for(auto it=from;it!=to;it++)
		{
			b.push_back(b.back()+f(*it));
			c.push_back(c.back()+rm[*it]);
		}
		auto pivot=stable_partition(from,to,f);
		l=new wavelet_tree(from,pivot,lo,mid);
		r=new wavelet_tree(pivot,to,mid+1,hi);
	}
	
	//k'th smallest element in subarray [l,r]
	int kth(int l,int r,int k)
	{
		if(l>r) return 0;
		if(lo==hi) return lo;
		int inLeft=b[r]-b[l-1];
		int lb=b[l-1],rb=b[r];
		if(k<=inLeft) return this->l->kth(lb+1,rb,k);
		return this->r->kth(l-lb,r-rb,k-inLeft);
	}
	
	//number of elements <=k in subarray [l,r]
	int LTE(int l,int r,int k)
	{
		if(l>r || k<lo) return 0;
		if(hi<=k) return r-l+1;
		int lb=b[l-1],rb=b[r];
		int x=this->l->LTE(lb+1,rb,k);
		int y=this->r->LTE(l-lb,r-rb,k);
		return x+y;
	}
	
	//number of occurences of k in subarray [l,r]
	int count(int l,int r,int k)
	{
		if(l>r || k<lo || k>hi) return 0;
		if(lo==hi) return r-l+1;
		int lb=b[l-1],rb=b[r];
		int mid=(hi+lo)/2;
		if(k<=mid) return this->l->count(lb+1,rb,k);
		return this->r->count(l-lb,r-rb,k);
	}
	
	//sum of elements <=k in subarray [l,r]
	ll sumk(int l,int r,int k)
	{
		if(l>r || k<lo) return 0;
		if(hi<=k) return c[r]-c[l-1];
		int lb=b[l-1],rb=b[r];
		ll x=this->l->sumk(lb+1,rb,k);
		ll y=this->r->sumk(l-lb,r-rb,k);
		return x+y;
	}
	
	~wavelet_tree() { delete l; delete r; }
		
};

void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>ara[i];
		S.insert(ara[i]);
	}
	int it=0;
	for(int e: S)
	{
		M[e]=++it;
		rm[it]=e;
	}
	for(int i=1;i<=n;i++) ara[i]=M[ara[i]];
	
	wavelet_tree *wt=new wavelet_tree(ara+1,ara+n+1,1,S.size());
	
	//your code goes here
	
	delete(wt);
}	
