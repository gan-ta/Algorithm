#include <cstdio>
#include <queue>
using namespace std;

typedef struct location{
	int position;
	int t;
}location;

queue<location> q;
int visited[200001];

int main()
{
	int n, k;
	int res = 100002;
	scanf("%d", &n);
	scanf("%d", &k);


	location start;
	start.position = n;
	start.t = 0;
	q.push(start);


	while (!q.empty())
	{
		location search = q.front();
		location s1, s2, s3;
		q.pop();
		visited[search.position] = 1;
		if (search.position == k)
		{
			if (res > search.t)
			{
				res = search.t;
			}
		}

		s1.position = search.position * 2;
		s1.t = search.t;
		if (s1.position < 200001)
		{
			if (visited[s1.position] == 0 && res > search.t)
			{
				q.push(s1);
			}
		}

		s2.position = search.position - 1;
		s2.t = search.t + 1;
		if (s2.position >= 0)
		{
			if (visited[s2.position] == 0 && res > search.t)
			{
				q.push(s2);
			}
		}

		s3.position = search.position + 1;
		s3.t = search.t + 1;
		if (s3.position < k+1)
		{
			if (visited[s3.position] == 0 && res > search.t)
			{
				q.push(s3);
			}
		}

	}

	printf("%d\n", res);

	return 0;
}