#include <iostream>
using namespace std;
int arr[301][301] = { 0, };

int main()
{
	int N, M;
	cin >> N >> M;
	int i, j, k;
	int T;
	int a, b, x, y;
	int res;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
		}
	}

	cin >> T;
	for (k = 0; k < T; k++)
	{
		cin >> a >> b >> x >> y;
		cout << arr[x][y] - arr[a - 1][y] - arr[x][b - 1] + arr[a - 1][b - 1] << endl;
	}
	return 0;
}