#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+55;
char s[N];
long long cnt[N<<2];
struct SAM{
    int ch[N<<1][26],fa[N<<1],l[N<<1],size[N<<1],k[N<<1],c[N<<1],pos[N<<1],belong[N<<1],fat[21][N<<1];
    int last,tot;

    void init() {
        last=tot=1;
        memset(ch[1],0,sizeof ch[1]);
    }
    void ins(int c,int id) {
        int p=last,np=++tot;last=np;l[np]=l[p]+1;
        memset(ch[tot],0,sizeof ch[tot]);
        for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
        if(!p)fa[np]=1;
        else {
            int q=ch[p][c];
            if(l[p]+1==l[q])fa[np]=q;
            else {
                int nq=++tot;l[nq]=l[p]+1;
                memcpy(ch[nq],ch[q],sizeof(ch[q]));
                fa[nq]=fa[q];fa[q]=fa[np]=nq;
                for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
            }
        }
        size[np]=1;
        pos[np]=id;
        belong[id]=np;
    }
    void build() {
        init();
        scanf("%s",s+1);
        int n=strlen(s+1);
        assert(n<=200000);
        for(int i=1;i<=n;i++) ins(s[i]-'a',i);
        for(int i=1;i<=tot;i++) c[l[i]]++;
        for(int i=1;i<=tot;i++) c[i]+=c[i-1];
        for(int i=1;i<=tot;i++) k[c[l[i]]--]=i;
        for(int i=1;i<=tot;i++) c[i]=size[i]=0;

        for(int id=tot;id>1;id--) {
            int i=k[id];
            fat[0][i] = fa[i];
            pos[fa[i]]^=pos[i];
            cnt[pos[i]]=cnt[pos[i]]+l[i]-l[fa[i]];
        }
        fat[0][1]=0;
        for (int i=1;i<=20;i++)
            for (int j=1;j<=tot;j++)
               fat[i][j]=fat[i-1][fat[i-1][j]];
        int m;
        scanf("%d",&m);
        assert(m<=200000);
        while(m--) {
            int L,R,id;
            scanf("%d%d",&L,&R);

            assert(L<=R);
            assert(R<=200000);
            id = belong[R];
            for(int i=20;i>=0;i--) {
                if(l[fat[i][id]]+1>R-L+1) {
                    id = fat[i][id];
                }
            }
            printf("%lld\n",cnt[pos[id]]);
        }
    }
}sam;


int main() {

    freopen("./data/data20.in","r",stdin);
    freopen("./data/data20.out","w",stdout);
    sam.build();
}
