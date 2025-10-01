	unsigned total = 0;
	unsigned char *ptrBytes = (unsigned char *)p;
	for (int index = 0; index < n; index++)
	{
		total += ptrBytes[index];
	}
	return total;