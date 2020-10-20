template<int N,ll mod>
struct Matrix
{
	#define rep(i,n) for(int i=0;i<n;i++)
	vector<vector<ll>>ara;
	
	ll normalize(ll x) { x%=mod; if(x<0) x+=mod; return x; }
	Matrix(bool identity=false) { ara.assign(N,vector<ll>(N,0)); if(identity) rep(i,N) ara[i][i]=1; }
	Matrix operator = (const Matrix &a) { ara=a.ara; return *this; }
	Matrix operator *= (const Matrix &a)
	{
		Matrix b;
		rep(i,N) rep(j,N) rep(k,N) b.ara[i][k]=normalize(b.ara[i][k]+normalize((ara[i][j]*a.ara[j][k])));
		ara=b.ara;
		return b;
	}
	Matrix operator += (const Matrix &a)
	{
		Matrix b;
		rep(i,N) rep(j,N) b.ara[i][j]=normalize(a.ara[i][j]+ara[i][j]);
		return b;
	}
	Matrix operator -= (const Matrix &a)
	{
		Matrix b;
		rep(i,N) rep(j,N) b.ara[i][j]=normalize(ara[i][j]-a.ara[i][j]);
		return b;
	}
	friend Matrix operator + (Matrix a,const Matrix &b) { return a+=b; }
	friend Matrix operator - (Matrix a,const Matrix &b) { return a-=b; }
	friend Matrix operator * (Matrix a,const Matrix &b) { return a*=b; }
	friend Matrix power(Matrix b,ll n) { Matrix ans(true); for(;n>0;n/=2,b*=b) if(n&1) ans*=b;return ans; }
	friend Matrix operator ^ (Matrix b,ll n) { return power(b,n); }
	friend ostream& operator << (ostream& out,const Matrix& a)  
	{
		rep(i,N) { rep(j,N) out<<a.ara[i][j]<<" "; out<<"\n";}
		return out;
	}
};

const ll mod=1e9+7;
typedef Matrix<2,mod> matrix;
