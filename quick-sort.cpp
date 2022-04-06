#include <iostream>
using namespace std;


int mark(int a[], int low, int high){
    int pivot = a[high];    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}
void quickSort(int a[], int l, int h){
    int k;
    if (l < h)
    {
        k  = mark(a,l,h);
 
        quickSort(a,l,k-1);
        quickSort(a,k+1,h);
    }
}

int main(){
    int a[100], l, r,n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

