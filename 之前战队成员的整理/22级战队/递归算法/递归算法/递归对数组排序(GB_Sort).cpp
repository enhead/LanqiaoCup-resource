#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN],b[MAXN],n;
void merge(int l,int r)
{
    int mid=(l+r)>>1;
    int i=l,j=mid+1,tmp=i;//进行二分回到一开始分割的两段，此时a[i...mid]和a[j...r]都是已经排序好的两个序列了。
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])
        {
            b[tmp++]=a[i++];
        }
        else
        {
            b[tmp++]=a[j++];
        }
    }
    /*此时一定是一个序列已经被拿走，另一个序列还有若干个没有被拿走的元素，全部放到末尾，因为一定比前面大*/
    while(i<=mid)
    {
        b[tmp++]=a[i++];
    }
    while(j<=r)
    {
        b[tmp++]=a[j++];
    }
    /*将临时数组排序好的大长度的序列覆盖到原来的数组中*/
    for(int k=l;k<=r;k++)
    {
        a[k]=b[k];
    }
}
void GB_sort(int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int mid=l+r>>1;//二分划段
    GB_sort(l,mid);//递归求有序的左区间
    GB_sort(mid+1,r);//递归求有序的右区间
    merge(l,r);//将两个递归得到的有序区间进行合并，得到长的有序区间。
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    GB_sort(1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}