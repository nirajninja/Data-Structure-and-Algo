int find(int a[],int x)
{
    if(a[x]==x) return x;
    a[x]=find(a,a[x]);
    return a[x];
}
void unionSet(int A[],int X,int Z)
{
    
    int u=find(A,X);
    int v=find(A,Z);
    if(u==v) return;
    A[u]=v;
    
}
