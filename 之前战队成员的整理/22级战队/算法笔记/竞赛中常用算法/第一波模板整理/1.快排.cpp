/*
1.能用sort就用
    <数据类型>  a[100];
    sort(<begin>,<end>,(<cmp>))
    若没有cmp默认为从小排到大
    //例：
        sort(a,a+n);
    cmp是自己设置的bool函数，用来调整排序顺序
    //例：
        bool cmp(int a,int b){
            //这里我一般是这么写的：return（前者a）?（后者b）;//参数顺序
            //这个？表示你想让前者（前面的数）是大数还是小数

            return a>b;//让前面的数大
        }
        sort(a,a+n,cmp);
    此时是按照从小到大排

    配合结构体：
    //例：
        struct Node{
            int a,b;
            //接下来是重载小于号，当然是能用cmp函数，但这个更快
            bool operator<(const Node &other)const{
                //需要注意这里表示的是结构体内的这个在前，other在后
                if(a==other.a){
                    return b>other.b;
                }
                return a>other.a;
                //a大的排前面，若a相等才看b
            }
        }a[100];
        sort(a,a+n);//这样即可
*/
/*
2.快排思想（一般是用不到的，也尽量别用）（分治思想）
代码:
void quick_sort(int l,int r){
    //以第一个数为基准，会相对简单
    //基本思路就是以一个数为界，不断分小于等于这个的区间和大于等于的区间
    //分别设立左右标兵，左标兵找大于基准，右标兵找小的，找到后两个数交换，直到左右标兵相等时，与第一个基准数交换
    //但是需要注意的是：右标兵需要先出发，因为最后与第一个数交换，应该要小的放前面
    if(l>=r){
        return;
    }
    int flag=a[l];
    int i=l,j=r;//左右标兵
    while(i<j){
        while(a[j]>=flag&&i<j){//嵌套循环都是要主要上层循环的条件
            //注意要等于
            j--;
        }
        while(a[i]<=flag&&i<j){
            i++;
        }
        swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    quick_sort(l,j-1);
    quick_sort(j+1,r);
}



*/

#include<bits/stdc++.h>
using namespace std;
int a[100];
void quick_sort(int l,int r){
    //以第一个数为基准，会相对简单
    //基本思路就是以一个数为界，不断分小于等于这个的区间和大于等于的区间
    //分别设立左右标兵，左标兵找大于基准，右标兵找小的，找到后两个数交换，直到左右标兵相等时，与第一个基准数交换
    //但是需要注意的是：右标兵需要先出发，因为最后与第一个数交换，应该要小的放前面
    if(l>=r){
        return;
    }
    int flag=a[l];
    int i=l,j=r;//左右标兵
    while(i<j){
        while(a[j]>=flag&&i<j){//嵌套循环都是要主要上层循环的条件
            //注意要等于
            j--;
        }
        while(a[i]<=flag&&i<j){
            i++;
        }
        swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    quick_sort(l,j-1);
    quick_sort(j+1,r);
}
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++ ){
        cout<<a[i]<<"  ";
    }
    return 0;
}