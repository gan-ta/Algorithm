#include<stdio.h>

int fun(int N, int K)
{
	if (N == K)
	{
		return 1;
	}
	else if (K == 0)
	{
		return 1;
	}
	else
	{
		return fun(N - 1, K) + fun(N - 1, K - 1);
	}
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", fun(N, K));
	return 0;
}