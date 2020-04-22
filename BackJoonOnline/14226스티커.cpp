#include <cstdio>
#include <queue>
using namespace std;

typedef struct imo{
	int total;
	int storage;
	int depth;
}imo;


int visited[2001][2001];
queue<imo> q;

int main()
{
	int s;
	int res = 0;
	scanf("%d", &s);

	imo start;
	start.total = 1;
	start.storage = 0;
	start.depth = 0;

	q.push(start);

	visited[1][0] = 1;

	while (1)
	{
		imo search;
		imo s1, s2, s3;
		search = q.front();
		q.pop();

		if (search.total == s)
		{
			res = search.depth;
			break;
		}

		s1.total = search.total;
		s1.storage = search.total;
		s1.depth = search.depth + 1;
		if (visited[s1.total][s1.storage] == 0)
		{
			visited[s1.total][s1.storage] = 1;
			q.push(s1);
		}

		s2.total = search.total + search.storage;
		s2.storage = search.storage;
		s2.depth = search.depth + 1;
		if(s2.total  < 2001)
		{
			if (visited[s2.total][s2.storage] == 0)
			{
				visited[s2.total][s2.storage] = 1;
				q.push(s2);
			}
		}

		s3.total = search.total - 1;
		s3.storage = search.storage;
		s3.depth = search.depth + 1;
		if (s3.total > 0)
		{
			if (visited[s3.total][s3.storage] == 0)
			{
				visited[s3.total][s3.storage] = 1;
				q.push(s3);
			}
		}
		
	}

	printf("%d\n", res);
	return 0;
}