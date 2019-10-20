#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
class myVector{
private:
    int* arr;
    int cap, sz;
public:
    myVector(){
        arr = new int[1];
        cap = 1;
        sz = 0;
    }
    void pop(){
        sz--;
    }
    int size(){
        return sz;
    }
    int getcap(){
        return cap;
    }
    void print(){
        for(int i = 0; i < sz; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    int get(int idx){
        if(idx >= sz)
            return -1;
        return arr[idx];
    }
    void push(int data, int idx){
        if(idx < sz)
            arr[idx] = data;
        else
            cout << "Wrong index!" << endl;
    }
    void push(int data){
        if(sz == cap){
            int* tmp = new int[2*cap];
            cap *=2;
            for(int i=0;i<sz;++i)
                tmp[i] = arr[i];
            delete[] arr;
            arr = tmp;
        }
        arr[sz] = data;
        sz++;
    }
};
int main(){
    myVector v; 
    v.push(10); 
    v.push(20); 
    v.push(30); 
    v.push(40); 
    v.push(50); 

    cout << "Vector size : "
        << v.size() << endl; 
    cout << "Vector capacity : "
        << v.getcap() << endl; 

    cout << "Vector elements : "; 
    v.print(); 

    v.push(100, 1); 

    cout << "\nAfter updating 1st index"
        << endl; 

    cout << "Vector elements : "; 
    v.print(); 

    cout << "Element at 1st index : "
        << v.get(1) << endl; 

    v.pop(); 

    cout << "\nAfter deleting last element"
        << endl; 

    cout << "Vector size : "
        << v.size() << endl; 
    cout << "Vector capacity : "
        << v.getcap() << endl; 

    cout << "Vector elements : "; 
    v.print(); 

    return 0; 
}
