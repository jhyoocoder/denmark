#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctype.h>
#include<algorithm>
using namespace std;

int a[100001], num[26]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0}, n, ok;
char c, yong[5];

int main()
{
	int i, j, len, gop;
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		gop=1000000;

		for(j=0; ; j++)
		{
			if(gop==0) break;
			scanf("%1c", &c);

			if(isdigit(c))
			{
				a[i]+=(c-'0')*gop;
				gop/=10;
			}

			if(isalpha(c))
			{
				a[i]+=num[c-'A']*gop;
				gop/=10;
			}
		}
	}

	sort(a, a+n);

	a[n]=-1;
	int cnt=1;

	for(i=1; i<=n; i++)
	{
		if(a[i]==a[i-1]) cnt++;
		else
		{
			if(cnt!=1)
			{
				printf("%03d-%04d %d\n", a[i-1]/10000, a[i-1]%10000, cnt);
				ok=1;
			}

			cnt=1;
		}
	}

	if(ok==0) printf("No duplicates.\n");

	return 0;
}