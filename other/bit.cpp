void update(int x,int d){
    while(x<=N){
        b[x]+=d;
        x = x + (-x)&x;
    }
}
int query(int x){
    int sum = 0;
    while (x){
            sum += b[x];
            x -= x & (-x);
        }
        return sum;
}
