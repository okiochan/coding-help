int main()
{
	int **arr = new int* [n];

	FOR(i,0,n)
	{
	arr[i] = new int[m];
    }

	FOR(i,0,n)
    {
    delete []arr[i]; 
    }
}