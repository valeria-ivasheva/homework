#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int get(int x, int parent[])
{
	int root = x;
	while (parent[root] != root)
	{
		root = parent[root];
	}
	int i = x;
	int j = 0;
	while (parent[i] != i)
	{
		j = parent[i];
		parent[i] = root;
		i = j;
	}
	return root;
}

void unionNode(int x, int y, int parent[], int rank[])
{
	x = get(x, parent);
	y = get(y, parent);
	if (x == y)
	{
		return;
	}
	if (rank[x] == rank[y])
	{
		rank[x]++;
	}
	if (rank[x] < rank[y])
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
	}
}

struct Edge
{
	int firstVertex;
	int nextVertex;
	int weight;
};

bool compare(const Edge &a, const Edge &b) 
{
	return a.weight < b.weight;
}

int main()
{
	FILE *text = fopen("text.txt", "r");
	if (text == nullptr)
	{
		cout << "Can't open file" << endl;
		return -1;
	}
	vector<Edge> graph;
	int count = 0;
	char str[100] = "";
	int numberLine = 0;
	int j = 0;
	while (fgets(str, 100, text) != nullptr)
	{ 
		int i = 0;
		numberLine++;
		int numberColumn = 0;
		while (str[i] != '\0')
		{
			string tempStr = "";
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
			{
				tempStr += str[i];
				i++;
			}
			if (str != "")
			{
				numberColumn++;
			}
			if (numberLine < numberColumn && stoi(tempStr) != 0)
			{
				Edge temp = { numberLine, numberColumn, stoi(tempStr) };
				graph.push_back(temp);
			}
			i++;
		}
	}
	fclose(text);
	sort(graph.begin(), graph.end(), compare);
	count = numberLine;
	int parent[10] = {};
	int rank[10] = {};
	for (int i = 1; i <= count; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	int size = graph.size();
	for (int i = 0; i < size; i++)
	{
		int from = graph[i].firstVertex;
		int to = graph[i].nextVertex;
		if (get(from, parent) != get(to, parent))
		{
			unionNode(from, to, parent, rank);
			cout << from << " " << to << " " << endl;
		}
	}
	return 0;
}