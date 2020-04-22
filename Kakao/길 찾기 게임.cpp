#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct node {
	int num;
	int x;
	int y;
	node* left;
	node* right;
}node;

vector<int> temp;

bool cmp(const node& a, const node& b)
{
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y > b.y;
	}
}

void addNode(node* parent, node* child)
{
	if (parent->x > child->x)
	{
		if (parent->left == NULL)
		{
			parent->left = child;
		}
		else
		{
			addNode(parent->left, child);
		}
	}
	else
	{
		if (parent->right == NULL)
		{
			parent->right = child;
		}
		else
		{
			addNode(parent->right, child);
		}
	}
}

void preorder(node* search)
{
	if (search == NULL) return;
	temp.push_back(search->num);
	preorder(search->left);
	preorder(search->right);
}

void postorder(node* search)
{
	if (search == NULL) return;
	postorder(search->left);
	postorder(search->right);
	temp.push_back(search->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<node> node_list;
	int i, j, k;

	for (i = 0; i < nodeinfo.size(); i++)
	{
		node_list.push_back({ i + 1,nodeinfo[i][0],nodeinfo[i][1],NULL,NULL });
	}

	sort(node_list.begin(), node_list.end(), cmp);

	node* root = &node_list[0];

	for (i = 1; i < node_list.size(); i++)
	{
		addNode(root, &node_list[i]);
	}

	preorder(root);

	answer.push_back(temp);
	temp.clear();

	postorder(root);
	answer.push_back(temp);
	return answer;
}