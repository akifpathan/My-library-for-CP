
/*
 * O(n) pattern matching algorithm
 * pi[i] denotes the maximum length of suffix
 * ended at position(i) which is also a prefix
 * of the string 
 * call with KMP kmp(x) where x is the desired string
*/

struct KMP
{
	int n;
	string p;
	vector<int>pi;
	
	KMP(const string &x)
	{
		n=x.size();
		p=x;
		pi.assign(n,-1);
	}
	
	void prefix_function()
	{
		for(int i=1,now=-1;i<n;i++)
		{
			while(now!=-1 && p[now+1]!=p[i]) now=pi[now];
			if(p[now+1]==p[i]) now++;
			pi[i]=now;
		}
		
		//only when p=pattern+#+text type
		for(int &x: pi) x++;
	}
};
