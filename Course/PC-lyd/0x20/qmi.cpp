int qmi(int m, int k)
{
	int res = 1, t = m;
	while (k)
	{
		if (k & 1) res = res * t;
		t = t * t;
		k >>= 1;
	}
	return res;
}