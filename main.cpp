#include<iostream>

using namespace std;

int a[210][210];

int expe[210];
bool vis[210];

int main()
{
	FILE* in = fopen("input.txt", "r");
	int n = 0;
	fscanf(in, "%d", &n);
	for(int i=1;i<n;i++)
	{
		int j = i + 1;
		while(fscanf(in,"%d",&a[i][j])!=EOF)
		{
			j++;
			if (j == n + 1)
			{
				break;
			}
		}
	}
	fclose(in);
	memset(expe, 0x3f, sizeof(expe));
	expe[1] = 0;
	for(int i=1;i<=n;i++)
	{
		int t = -1;
		for(int j=1;j<=n;j++)
		{
			if (!vis[j] && (t == -1 || expe[t] > expe[j]))
			{
				t = j;
			}
		}
		vis[t] = true;
		for(int j=t+1;j<=n;j++)
		{
			expe[j] = min(expe[j], expe[t] + a[t][j]);
		}
	}
	FILE* out = fopen("output.txt", "w");
	fprintf(out, "%d", expe[n]);
	return 0;
	return 0;
}