#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
#include <ostream>

template <class T>
class array
{
    int lb, ub;   
    T a[100];     

    public:
    array();                              
    void setLB(int x);                   
    void setUB(int x);                    
    int  getLB();                         
    int  getUB();                         
    void create();                        
    void insert_at_end(T key);            
    void insert_at_beginning(T key);      
    void insert_at_position(int, T key);  
    void delete_at_end();                 
    void delete_at_beginning();           
    void delete_at_position(int);         
    template<class U> friend ostream& operator<<(ostream&, const array<U>&);
};