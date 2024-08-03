void Dec(int i, int n){
    if(i>n)
        return;
    Dec(i+1,n);
    cout<<i<<endl;
}
int main(){
    int n; cin>>n; 
    Dec(1,n);
    return 0; 
}