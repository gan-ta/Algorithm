#include <iostream>
#include <deque>
using namespace std;

deque<int> queue;
int pick[51];

int main()
{
	int N, M;
	int check = 0;
	cin >> N >> M;
	int i, j, l;
	for (i = 1; i <= M; i++)
	{
		cin >> pick[i];
	}

	for (i = 0; i < N; i++)
	{
		queue.push_back(i + 1);
	}

	for (i = 1; i <= M; i++)
	{
		for (j = 0; j < queue.size(); j++)
		{
			if (queue[j] == pick[i])
				break;
		}
		if (j <= queue.size() / 2)
		{
			while (j > 0)
			{
				int temp;
				temp = queue.front();
				queue.pop_front();
				queue.push_back(temp);
				j--;
				check++;
			}
			queue.pop_front();
		}
		else
		{
			while (j < queue.size() - 1)
			{
				int temp;
				temp = queue.back();
				queue.pop_back();
				queue.push_front(temp);
				j++;
				check++;
			}
			int temp;
			temp = queue.back();
			queue.pop_back();
			queue.push_front(temp);
			check++;
			queue.pop_front();
		}
	}
	cout << check << endl;
	return 0;
}