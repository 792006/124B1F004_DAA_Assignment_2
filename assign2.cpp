#include<vector>
#include<algorithm>
using namespace std;
int partition(vector<int> &arr,int lb,int ub){
        int pivot=arr[lb];
        int start=lb;
        int end=ub;
        while(start<end){
                while(start<=ub && arr[start]<=pivot){
                        start++;
                }
                while(end>=lb && arr[end]>pivot){
                        end--;
                }
                if(start<end){
                        swap(arr[start],arr[end]);
                }
        }
        swap(arr[lb],arr[end]);
        return end;
}
void quickSort(vector<int> &v,int lb,int ub){
        if(lb>=ub){
                return;
        }
        int loc=partition(v,lb,ub);
        quickSort(v,lb,loc-1);
        quickSort(v,loc+1,ub);
}
int main(){
        vector<int> arr(10);
        cout<<"Enter the Elements:\n";
        for(int i=0;i<arr.size();i++){
                cout<<"Enter element at "<<i<<" :";
                cin>>arr[i];
        }
        cout<<"Array Now :";
        for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        quickSort(arr,0,arr.size()-1);
        cout<<"Array Then: ";
        for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
        }
}
