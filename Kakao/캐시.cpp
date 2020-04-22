#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int i, j;
	int min = 100002;
	map<string, int> cache;
	for (i = 0; i < cities.size(); i++)
	{
		string search = cities[i];
		transform(search.begin(), search.end(), search.begin(), ::tolower);
		min = 100002;
		if (cache.count(search) == 0)
		{
			if (cacheSize > cache.size())
			{
				cache[search] = i;
			}
			else
			{
				if (cacheSize != 0)
				{
					map<string, int>::iterator out;
					for (auto it = cache.begin(); it != cache.end(); it++)
					{
						if (min > it->second)
						{
							min = it->second;
							out = it;
						}
					}
					cache.erase(out->first);
					cache[search] = i;
				}
			}
			answer += 5;
		}
		else
		{
			answer += 1;
			cache[search] = i;
		}

	}
	return answer;
}