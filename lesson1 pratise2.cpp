#include <iostream>

using namespace std;
const int N = 1000;
int a[N*4],ans[N],n;
int lowbit(int x)
{
	return x&-x;
}
void add(int x, int k)
{
	while(x <= 32001)
	{
		a[x] += k;
		x = x+lowbit(x);
	}
}
int get(int x)
{
	int ans = 0;
	while(x)
	{
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}
int main() 
{
	int x,y;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d%d",&x,&y);
		x ++;
		int t = get(x);
		ans[t]++;
		add(x,1);
	}
	for(int i = 0; i < n; i++)
	printf("%d\n",ans[i]);
	return 0;
}

