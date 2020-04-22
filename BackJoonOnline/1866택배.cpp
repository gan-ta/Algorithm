#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> box;
int M[3001] = { 0, }; 
int H_result[3001][3001] = { 0, };
int truck, helecopter;


int main()
{
	int N;
	cin >> N;
	int i, j;
	int temp = 0;
	int mid = 0;
	box.push_back(0);
	for (i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		box.push_back(temp);
	}
	sort(box.begin(), box.end());
	cin >> truck;
	cin >> helecopter;

	
	
	int temp1 = 0;
	int temp2 = 0;
	int check = 1;
	for (i = 1; i <= N; i++)
	{
		temp1 += box[i] - box[1];
		H_result[1][i] = temp1 * truck;
	}

	
	for (i = 2; i <= N; i++)
	{
		temp2 = box[i] - box[i - 1];
		for (j = i - 1; j >= 1; j--)
		{
			H_result[i][j] = H_result[i - 1][j] + (temp2 * check) * truck;
			check++;
		}
		check = 1;
		for (j = i; j <= N; j++)
		{
			H_result[i][j] = H_result[i - 1][j] - (temp2 * check) * truck;
			check++;
		}
		check = 1;
	}


	for (i = 1; i <= N; i++) 
	{
		mid = (1 + i) / 2;
		M[i] += (helecopter + H_result[mid][i]);
		M[i] += H_result[mid][1];
	}

	for (i = 1; i <= N; i++)
	{
		temp = M[i - 1] + (box[i] * truck);

		if (M[i] > temp)
		{
			M[i] = temp;
		}

		temp = M[i - 1] + helecopter;
		if (M[i] > temp)
		{
			M[i] = temp;
		}

		temp = 0;

		for (j = i - 1; j >= 1; j--)
		{
			mid = (j + i) / 2;
			temp += helecopter;
			temp += M[j - 1];
			temp += H_result[mid][i];
			temp += H_result[mid][j];
			if (M[i] > temp)
			{
				M[i] = temp;
			}
			temp = 0;
		}

	}

	cout << M[N] << endl;

	return 0;
}

