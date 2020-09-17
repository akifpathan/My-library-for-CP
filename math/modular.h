template<typename T,typename U>
T power(T b,U n)
{
	assert(n>=0);
	T ans=1;
	for(;n>0;n/=2,b*=b) if(n&1) ans*=b;
	return ans;
}
ll power(ll b,ll n,ll mod)
{
	assert(n>=0);
	ll ans=1;
	for(;n>0;n/=2,b=(b*b)%mod) if(n&1) ans=(ans*b)%mod;
	return ans;
}

template<ll mod>
struct Modular
{
	ll val;
	
	Modular(){ }
	Modular(ll _val) { val=_val; }
	
	Modular normalize(const ll x) {val=x%mod; val+=mod; val%=mod; return val; }
	
	Modular operator = (ll x) { return normalize(x); }
	Modular operator = (const Modular &x){val=x.val;return *this;}
	Modular operator += (const Modular &a) {return normalize(val+a.val); }
	Modular operator -= (const Modular &a) {return normalize(val-a.val);  }
	Modular operator *= (const Modular &a) {return normalize(val*a.val);}
	Modular operator /= (const Modular &b) {return normalize(val*inverse(b).val); }
	
	//friend Modular power(Modular b,ll n) {Modular ans=1; for(;n>0;n/=2,b*=b) if(n&1) ans*=b;return ans; }
	friend Modular operator ^ (Modular b,ll n) { return power(b,n); }
	friend Modular inverse(Modular b) { return b^(mod-2); }
	
	friend Modular operator + (Modular a,const Modular &b) { return a+=b; }
	friend Modular operator - (Modular a,const Modular &b) { return a-=b; }
	friend Modular operator * (Modular a,const Modular &b) { return a*=b; }
	friend Modular operator / (Modular a,const Modular &b) { return a/=b; }
	
	friend Modular operator + (Modular a,ll b) { return a+=b; }
	friend Modular operator - (Modular a,ll b) { return a-=b; }
	friend Modular operator * (Modular a,ll b) { return a*=b; }
	friend Modular operator / (Modular a,ll b) { return a/=b; }
	
	friend Modular operator + (ll b,Modular a) { return a+=b; };
	friend Modular operator - (ll b,const Modular &a) { Modular c(b); return c-=a; }
	friend Modular operator * (ll b,Modular a) { return a*=b; };
	friend Modular operator / (ll b,const Modular &a) { Modular c(b); return c/=a; }
	
	friend istream& operator >> (istream& in,Modular &a) {ll x; in>>x; a.normalize(x); return in; }
 
    friend ostream& operator << (ostream& out,const Modular& a) { return out<<a.val; }
};

//const ll mod=998244353;
const ll mod=1e9+7;
using Mint = Modular<mod> ;

vector<Mint>fact(1,1);
vector<Mint>inv_fact(1,1);

Mint C(int n,int k)
{
	if(k<0 || k>n) return 0;
	while((int)fact.size()<n+1)
	{
		Mint x=fact.back()*fact.size();
		fact.push_back(x);
		inv_fact.push_back(1/x);
	}
	return fact[n]*inv_fact[k]*inv_fact[n-k];
}
