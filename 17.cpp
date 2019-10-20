#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int merge(vector<int> arr, vector<int> temp, int left, 
        int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] > 2 * arr[j]) { 
            inv_count += (mid - i); 
            j++; 
        } 
        else { 
            i++; 
        } 
    } 
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
    return inv_count; 
} 
/*int merge(vector<int> a, vector<int> b, int left,int newStart, int right){
  int invCount = 0;
  int i, j, k;
  i=left; j=newStart;
  while(i<=newStart-1 && j<=right){
  if(a[i] > 2*a[j]){
  invCount += (newStart-i);
  j++;
  }
  else
  i++;
  }
  i=left; j=newStart; k=left;
  while(i <= newStart-1 && j <= right){
  if(a[i] <= a[j]){
  b[k++] = a[i++];
  }
  else{
  b[k++] = a[j++];
  }
  }
  while(i<=newStart-1)
  b[k++] = a[i++];
  while(j<=right)
  b[k++] = a[j++];
  for(int i = left; i <= right; ++i)
  a[i] = b[i];
  return invCount;
  }
int mergeSortHelper(vector<int> a, vector<int> b, int left, int right){
    int mid = (right + left)/2;
    int invCount = 0;
    if(left < right){
        invCount += mergeSortHelper(a,b,left,mid);
        invCount += mergeSortHelper(a,b,mid+1,right);
        invCount += merge(a,b,left,mid+1,right);
    }
    return invCount;
}
int mergeSort(vector<int> a){
    int n = a.size();
    vector<int> temp(n);
    return mergeSortHelper(a, temp, 0, n-1);
}*/
int _mergeSort(vector<int> arr, vector<int> temp, int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
}
int mergeSort(vector<int> arr)
{
    int array_size = arr.size();
    vector<int> temp;
    temp.resize(array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
int main(){
    vector<int> a;
    a.pb(1);
    a.pb(20);
    a.pb(6);
    a.pb(4);
    a.pb(5);
    cout << mergeSort(a) << endl;
    return 0;
}
