#include <iostream>
using namespace std;
int main(){
    int n, suma=0;
    cout<<"Introduceti numarul de elemente:";
    cin>>n;
    int arr[n];
    cout<<"Introduceti elementele:"<<endl;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
        suma+=arr[i];
    }
    cout<<"Suma sirului de numere este:"<<suma<<endl;
    return 0;
}