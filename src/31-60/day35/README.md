``` c
int singleNumber(int*nums,int numSize)
{
	int res=0;
	for(int i=0;i<numSize;i++)
	{
		res^=nums[i];
	}
	return res;
}
```

