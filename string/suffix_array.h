/*
 * nlogn approach for suffix array
 * sa[i] denotes the position of i'th suffix in lexicographical order
 * sa[0]=n
 * lcp[i] denotes longest common prefix(sa[i-1],sa[i])
 * if we want to find lcp(i,j) then we need
 * to build a sparse table
 * lcp(i,j)=min(sparse_table.query(i+1,j))
*/

struct suffix_array {
	vector<int> sa, lcp;
	suffix_array(string& s, int lim=256) { // or basic_string<int>
		#define rep(i,a,b) for(int i=a;i<b;i++)
		int n = s.size() + 1, k = 0, a, b;
		vector<int> x(s.begin(),s.end()+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(sa.begin(),sa.end(), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(y.begin(),y.end(), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(ws.begin(),ws.end(), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
		#undef rep
	}
};
