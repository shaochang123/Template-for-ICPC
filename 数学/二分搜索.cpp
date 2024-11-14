//二分，向下取下标
void binary_search(int a[],int x){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid]>x)r = mid-1;
        else if(a[mid]<x) l = mid+1;
        else {
            break;
        }
    }
    cout<<mid<<endl;
}
