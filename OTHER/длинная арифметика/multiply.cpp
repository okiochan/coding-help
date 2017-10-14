
const int POW = (int)1E9;
int arr[MAXN], len = 1; //в обратном порядке

mult( int num)
{//
	for(int i = 0; i < len; i++)
		arr[i] *= num;
	
	for(int i = 0; i < len; i++)
	{
		if(arr[i] >= POW)
		{
			if(i+1 == len) len++;

			arr[i + 1] += arr[i]/POW
			arr[i] = arr[i] % POW;
		}

	}

}//