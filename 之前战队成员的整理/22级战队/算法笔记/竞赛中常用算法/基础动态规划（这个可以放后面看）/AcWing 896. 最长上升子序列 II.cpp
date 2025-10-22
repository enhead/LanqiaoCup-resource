//贪心+二分
/*根据题意，我们添加一个数最好是加在前面子序列的最后（也就是最大）
    这个添加的过程肯定是按照顺序的，前面的加完才能加后面的；
    为了使结果最优化，那么每个位置上的数就需要尽量小
    （这样操作后的数列并不是实际的子序列，是我们是子序列上每个位置最小化的结果）
    （唉，感觉没说明白）
*/
//q[i]表示长度为i的结尾，并使结尾最小化
//对于每个a[i]需要刚好大于等于的值,也就是其中的最小值
//根据视频所讲这个q这个数列有严格的单调性，所以我们能用二分
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],q[maxn];
int main(){
    int n;
    cin>>n;
    int len=0;//计入q的长度，注意不是编号
    for(int i=0;i<n;i++){
        cin>>a[i];
    /*模板写法，会涉及到一点边界问题，尽量用函数
        //二分
        int l=0,r=len;
        while(l<r){//找符合条件的最小值,用向左模板
            int mid=(l+r)>>1;
            if(q[mid]>=a[i]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        q[l]=a[i];
        len=max(len,l+1);
        // printf("l=%d;ql=%d;len=%d\n",l,q[l],len);
    */
        int l=lower_bound(q,q+len,a[i])-q;
        //找的是a[l]==a[i]的最小位置，若不存在就找恰好大于的位置
        q[l]=a[i];
        len=max(len,l+1);
        // printf("l=%d;ql=%d;len=%d\n",l,q[l],len);
    }
    cout<<len;


    return 0;
}