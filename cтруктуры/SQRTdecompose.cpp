//gets sum from l to r
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);

	FOR(i, 0, n)
	{
		cin >> a[i];
	}

	int len = (int)sqrt(n + .0) + 1; // � ������ �����, � ���������� ������
	vector<int> b(len);

	for (int i = 0; i<n; ++i)
		b[i / len] += a[i];

	int q; cin >> q;
	while (q--)
	{
		int l, r; // ��������� ������� ������ - ��������� ������
		cin >> l >> r;

		int sum = 0;
		for (int i = l; i <= r; )
		{
			// ���� i ��������� �� ������ �����, ������� �������� � [l;r]
			if (i % len == 0 && i + len - 1 <= r) {

				sum += b[i / len];
				i += len;
			}
			else {
				sum += a[i];
				++i;
			}
		}
			
	}
}