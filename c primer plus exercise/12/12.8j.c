// #include<stdio.h>
int *make_array (int elem ,int val){
int m;

    

}
void show_array (const int ar [],int n){
    
    int *pa =(int*)malloc(sizeof(int)*8);
    int arr[8];
    pa=arr;
    for(int i=0 ;i<n ;i++){
        arr[i]=ar[i];
    }
}
int main(void){
    int *pa;
    int size;
    int value;

    printf("enter the number of elemwnts:");
    while(scanf("%d",&size) == 1 && size > 0){
printf("enter the number of elements:");
scanf("%d",&value);
pa=make_array(size ,value);
if(pa){
show_array(pa,size);
free(pa);

}printf("Enter the numer of elements (<1 to quit):");

}
printf("Done \n");
return 0;
}