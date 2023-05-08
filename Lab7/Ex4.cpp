#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
 for (int i = 0; i < n; i++) 
 {
 cout << arr[i] << " ";
 }
}
void hashing(int table[], int tsize, int arr[], int N)
{
 for (int i = 0; i < N; i++) 
 {
 int hv = arr[i] % tsize;
 if (table[hv] == -1)
 table[hv] = arr[i];
 else 
 {
 for (int j = 0; j < tsize; j++) 
 {
 int t = (hv + j * j) % tsize;
 if (table[t] == -1) 
 {
 table[t] = arr[i];
 break;
 }
 }
 }
 }
 printArray(table, N);
}
int main()
{
 int arr[] = {20,45,503,65,93,72,86,202};
 int N = 8;
 int L = 7;
 int hash_table[8];
 for (int i = 0; i < L; i++) 
 {
 hash_table[i] = -1;
 }
 hashing(hash_table, L, arr, N);
 return 0;
}