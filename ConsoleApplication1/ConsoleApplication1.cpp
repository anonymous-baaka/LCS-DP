#include<iostream>
#include<algorithm>
#define maxLength 10
using namespace std;

int lcs(string& o1, string& o2)
{
	int sz1 = o1.size();
	int sz2 = o2.size();
	int mat[maxLength][maxLength];
	for (int i = 0; i < o1.size() + 1; i++)
		mat[0][i] = 0;
	for (int i = 0; i < o2.size() + 1; i++)
		mat[i][0] = 0;

	for (int i = 1; i < o2.size()+1; i++)
	{
		for (int j = 1; j < o1.size() + 1; j++)
		{
			if (o1[j] == o2[i])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
		}
	}
	return mat[o2.size()][o1.size()];
}

int main()
{
	string s1 = "abcdd";
	string s2 = "abcdddd";
	cout<<lcs(s1, s2);
}