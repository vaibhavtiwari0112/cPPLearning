// By using smart pointers we can avoid memory leaks
// as by using smart pointers memory is automatically deallocated

#include<iostream>
#include<memory>

using namespace std;

class myClass{
    public:
    myClass(){
        cout<<"constructor"<<endl;
    }
    ~myClass(){
        cout<<"destructor"<<endl;
    }
};


int main(){
 // 1. Unique pointer
 // unique pointers are destroyed after the scope of the program block of which it is created
 // syntax of unique pointer with a value
    unique_ptr<int> unPtr1 = make_unique<int>(25); // assigned 25 value to the address to which unique pointer1 is pointing to.
    cout<<*unPtr1<<endl; // output: 25

   // unique_ptr<int> unPtr2 = unPtr1; // you can't copy unique pointer
    //instead of this do following
   unique_ptr<int> unPtr2 = move(unPtr1); // ownership of unique pointer1 is transferred to unique pointer2.
   cout<<*unPtr2<<endl;
  //cout<<*unPtr1<<endl; // output: null pointer



// regarding scope of unique pointer
    {
        unique_ptr<myClass> unPtr3 = make_unique<myClass>();
    }
// the above curly braces define the scope of unique pointer3.    
 // output : constructor
 // output : destructor
 
 // 2. shared pointer
 
 // creation of shared pointer
 {
    shared_ptr<myClass> shPtr1 = make_shared<myClass>();
cout<< "Shared Count: "<< shPtr1.use_count()<<endl;//1
 shared_ptr<myClass> shPtr2 = shPtr1;
 cout<< "Shared Count: "<< shPtr1.use_count()<<endl; // 2
 
 {
    shared_ptr<myClass> shPtr3 = shPtr1;
 cout<< "Shared Count: "<< shPtr1.use_count()<<endl; // output: 3
 }

  cout<< "Shared Count: "<< shPtr1.use_count()<<endl; // output: 2
 // this implies shared pointer 3 is deallocated after the scope

 }

 // 3. weak pointer
 // we use weak pointer to  locate an object in memory but that is not kept alive as it is in shared pointer

 {
    weak_ptr<int> wePtr1;
    {
        shared_ptr<int> shPtr4 = make_shared<int>(40);
        wePtr1 = shPtr4;
    }
 }

system("pause>null"); 
    return 0;
}