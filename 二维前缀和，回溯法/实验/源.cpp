#include<stdio.h>//二维前缀和
int a[5005][5005] = { 0 };
int max(int a, int b);
int main()
{
	int n, r;
	int i, j;
	int x, y, v;
	int ans=0;
	scanf("%d %d",&n,&r);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &v);
		a[x+1][y+1] += v;
	}
	for (i = 1; i <= 5001; i++)
	{
		for (j = 1; j <= 5001; j++)
		{
			a[i][j] += a[i - 1][j];
		}
	}
	for (i = 1; i <= 5001; i++)
	{
		for (j = 1; j <= 5001; j++)
		{
			a[i][j] += a[i][j - 1];
		}
	}
	for (i = r; i <= 5001; i++)
	{
		for (j = r; j <= 5001; j++)
		{
			ans = max(ans, a[i][j] + a[i - r][j - r] - a[i][j - r] - a[i - r][j]);
		}
	}
	printf("%d",ans);
	return 0;
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
/* 回溯法
#include<stdio.h>
#include<string.h>
int n, i, s, a[1000], b[1000], r;
char c[1000];
int  f(int step)
{
	int r;
	if (step == n + 1)
	{
		s++;
		for (r = 1; r <= n; r++)
			printf("%c", b[r] + 96);
		printf("\n");
		return 0;
	}
	for (r = 1; r <= 26; r++)
		if (a[r] > 0)
		{
			b[step] = r;
			a[r]--;
			f(step + 1);
			a[r]++;
		}
}
int main()
{
	scanf("%d", &n);
	scanf("%s", c);
	for (i = 0; i < n; i++)
		a[c[i] - 96]++;
	f(1);
	printf("%d\n", s);
	return 0;
}*/