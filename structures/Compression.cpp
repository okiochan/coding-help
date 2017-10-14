struct Compression {
	vector<int> a;
	Compression() {}
	void Reserve(int n) { a.reserve(n); }
	void Add(int x) { a.push_back(x); }
	void Compress() { sort(a.begin(), a.end());  a.resize(unique(a.begin(), a.end()) - a.begin()); }
	int operator()(int x) { return lower_bound(a.begin(), a.end(), x) - a.begin(); }
	int Leq(int x) { return upper_bound(a.begin(), a.end(), x) - a.begin() - 1; }
	int Geq(int x) { return lower_bound(a.begin(), a.end(), x) - a.begin(); }
	int Inv(int x) { return a[x]; }
	int Size() { return a.size(); }
};