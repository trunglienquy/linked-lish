#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int a[], int n){
    for (int i = (n-1); i >=0 ; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
            
        }
        
    }
    
}

void slection_sort(int a[],int n){
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min]){
                min = j;
            }
        }
        if (min != i){
            swap(a[i],a[min]);

        }
        
    }
    
}

void xuat(int a[], int &n){
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i];
    }

}
int main(){
    int n;
    int a[20];
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Thuat toan bubble sort: " << endl;
    bubble_sort(a,n);
    xuat(a,n);
    cout << endl;
    cout << "Thuat toan slection sort: " << endl;
    slection_sort(a,n);
    xuat(a,n);
    
    return 0;
}