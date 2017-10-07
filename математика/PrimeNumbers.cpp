bool prime[N];

void erato()
{
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;

	for (int i = 2; i*i < N; i++)
	{
		if (prime[i])
		{
			for (int j = i*i; j < N; j += i)
			{
				if (prime[j]) prime[j] = 0;
			}
		}
	}
}