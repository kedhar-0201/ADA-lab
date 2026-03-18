#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int f,int mid,int l){
    int n1=mid-f+1;
    int n2=l-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[f+i];
    }
    for(int j=0;j<n2;j++){
        arr2[j]=arr[mid+1+j];
    }
    int k=f;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]>=arr2[j]){
            arr[k]=arr2[j];
            j++;
        }else{
            arr[k]=arr1[i];
            i++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int f,int l){
     if(f<l){
        int mid=(f+l)/2;
        mergesort(arr,f,mid);
        mergesort(arr,mid+1,l);
        merge(arr,f,mid,l);
    }
}
void main(){
    int n;
    printf("Enter the no.of elements: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i] = rand() % 1000;
    }
    clock_t start,end;
    start = clock();
    mergesort(arr,0,n-1);
    end = clock();
    float time_taken = ((float)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken = %lf seconds\n",time_taken);
}
