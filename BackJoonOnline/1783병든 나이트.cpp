#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int height, width;

	cin >> height >> width;

	if (height == 1)
	{
		cout << 1 << endl;
	}
	else if (height == 2)
	{
		cout << min(4, (width + 1) / 2) << endl;
	}
	else
	{
		if (width < 7)
		{
			cout << min(4, width);
		}
		else
		{
			cout << width - 2 << endl;
		}
	}

	return 0;
}