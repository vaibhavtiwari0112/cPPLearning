#include<iostream>

// RAII (Resource Acquisition In Initialization) to build up working of smart pointers

using namespace std;

void func(){
    for(int i=0;i<10;i++){
        cout<<"hey"<<endl;
        int *a = new int(10); // it will allocate memory in Heap
    delete a; // to free memory to avoid memory leaks
    // instead of using delete we use smart pointers to take care of this by cpu.

    }
}

class Wrappper{
    private:
          int* mem;
public:
Wrappper(int* a):mem(a){
    cout<<"constructor"<<endl;
}
~Wrappper(){
    cout<<"destructor"<<endl;
    delete mem;
}
};

int main(){
    //func();
    Wrappper obj(new int(10));
    return 0;
}