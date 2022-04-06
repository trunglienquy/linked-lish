#include <iostream>
using namespace std;

void shakerSort(int a[], int n)
{
	int l = 0, r = n-1, k = 0;
    while (l < r)
    {
        for (int i = r; i > l; i--)
        {
            if (a[i] < a[i-1])
            {
                swap(a[i],a[i-1]);
                k=i;
            }
            
        }
        l=k;
        for (int i = l; i < r; i++)
        {
            if (a[i] > a[i+1])
            {
                swap(a[i],a[i+1]);
                k=i;
            }
            
        }
        r=k;
        
        
    }
    
}
int main(){
    int a[100],n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    shakerSort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    
    
    return 0;
}