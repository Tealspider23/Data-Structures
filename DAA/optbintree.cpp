#include <iostream>
using namespace std;
int sum(int freq[], int i, int j);

int optCost(int freq[], int i, int j){
	if (j < i)
		return 0;
	if (j == i)
		return freq[i];
	int fsum = sum(freq, i, j);
	int min = INT_MAX;
	for (int r = i; r <= j; ++r)
	{int cost = optCost(freq, i, r-1) +
				optCost(freq, r+1, j);
		if (cost < min)
			min = cost;
	}
	return min + fsum;
}


int optimalSearchTree(int keys[],int freq[], int n)
{
return optCost(freq, 0, n - 1);
}


int sum(int freq[], int i, int j)
{
int s = 0;
for (int k = i; k <= j; k++)
s += freq[k];
return s;
}


int main()
{int keys[] = {1,4, 3,7};
int freq[] = {4, 5, 6};
int n = sizeof(keys) / sizeof(keys[0]);
cout << "Cost of Optimal BST is "<< optimalSearchTree(keys, freq, n);
return 0;
}






