
struct query
{
    int l,r,id;
   
    bool operator<(const query &a) const
    {
        int x=l/sz;
        int y=a.l/sz;
       
		if(x!=y) return x<y;
		if(x%2) return r<a.r;
		return r>a.r;
    }
} ques[mx];

void add(int indx)
{
    int x=ara[indx];
    int y=fre[x];
   
    cnt_of_fre[y]--;
    sum[y]-=x;
    fre[x]++;
    y++;
    cnt_of_fre[y]++;
    sum[y]+=x;
   
    now=max(now,y);
}
 
void baad(int indx)
{
    int x=ara[indx];
    int y=fre[x];
   
    if(now==y && cnt_of_fre[y]==1) now--;
   
    cnt_of_fre[y]--;
    sum[y]-=x;
    fre[x]--;
    y--;
    cnt_of_fre[y]++;
    sum[y]+=x;

} 

void solve()
{
	
	
	
	
	
	for(int i=1;i<=n;i++)
	{
		while(l>ques[i].l) add(--l);
		while(l<ques[i].l) baad(l++);
		while(r>ques[i].r) baad(r--);
		while(r<ques[i].r) add(++r);

		ans[ques[i].id]=sum[now];
	}

	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	
}
