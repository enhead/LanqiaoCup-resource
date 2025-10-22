__int128 read()//手写读入
{
	__int128 f=1,x=0;
	char c=getchar();//清掉空格
	if(c=='-') f=-1,c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
void write(__int128 x)//手写输出
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x / 10);
	putchar(x%10+'0');
	return;
}
//注意不能关掉c语言的同步
//输入   __int128 a=read();
//输出   write(a);