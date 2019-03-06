/*
 * • Classes
 *   Concrete Types; Abstract Types; Virtual Functions; Class Hierarchies
 *   • Copy and Move
 *   Copying Containers; Moving Containers; Resource Management; Suppressing Operations
 *   • Templates
 *   Parameterized Types; Function Templates; Function Objects; Variadic Templates; Aliases
 */

#include<initializer_list>


// Classes

//Concrete Class: Behaves exactly like built in type
// Can be allocated in a stack embedded in other objects etc.
class complex
{
    double re, im; // representation: two doubles
  public:
    /* Functions defined in a class are inlined by default
       Inlining important for efficiency */
       //Simple calls must be inline
    complex(double r, double i) : re{r}, im{i} {} // construct complex from two scalars
    complex(double r) : re{r}, im{0} {}           // construct complex from one scalar
    complex() : re{0}, im{0} {}                   // default complex: {0,0}
    double real() const { return re; }
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }
    complex &operator+=(complex z)
    {
        re += z.re, im += z.im;
        return *this;
    } // add to re and im
    // and return the result
    complex &operator-=(complex z)
    {
        re-= z.re, im-= z.im;
        return *this;
    }
    complex &operator*=(complex); // defined out-of-class somewhere
    complex &operator/=(complex); // defined out-of-class somewhere
};

class Vector
{
  private:
    double* elem; // elem points to an array of sz doubles
    int sz;

  public:
    Vector(int s) : elem{new double[s]}, sz{s} // constructor: acquire resources
    {
        for (int i = 0; i != s; ++i)
            elem[i] = 0; // initialize elements
    }
    Vector(std::initializer_list<double>); // initialize with a list
    ~Vector() { delete[] elem; } // destructor: release resources
    double &operator[](int i);
    int size() const;
    
};

Vector::Vector(std::initializer_list<double> lst) // initialize with a list
    : elem{new double[lst.size()]}, sz{lst.size()}
{
    // copy(lst.begin(), lst.end(), elem); // copy from lst into elem
}

// Every block: new scope, items are invisible to outside elements

/* Abstract Types 
Abstract type is a type that
completely insulates a user from implementation details. To do that, we decouple the interface
from the representation and give up genuine local variables. Since we don’t know anything about
the representation of an abstract type (not even its size), we must allocate objects on the free store
*/

class Container //Abstract class since it has atleast one pure virutal func
{
  public:
    virtual double &operator[](int) = 0; // pure virtual function : Child class must define the function
    virtual int size() const = 0;        // const member function - cant change member vars inside the func
                                         // Still possible to mutate vars if marked mutable (++11)
    virtual ~Container() {}              // destructor (§3.2.1.2)
};

class Vector_container : public Container
{ // Vector_container implements Container
    Vector v;

  public:
    Vector_container(int s) : v(s) {} // Vector of s elements
    ~Vector_container() {}
    double &operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

/* Virtual functions
 * Knowing which method to call (based on object type)
 * Done at runtime using virtual function table or simply the vtbl
 * Has mapping between class and function to call
 */

/* Use unique_ptr to ensure that ptr gets destroyed once it goes out of scope
 * Especially if using in containers
 */
unique_ptr<Shape> read_shape(istream &is) // read shape descriptions from input stream is
{
    // read shape header from is and find its Kind k
    switch (k)
    {
    case Kind::circle:
        // read circle data {Point,int} into p and r
        return unique_ptr<Shape>{new Circle{p, r}}; // §5.2.1
        // ...
    }
    void user()
    {
        vector<unique_ptr<Shape>> v;
        while (cin)
            v.push_back(read_shape(cin));
        draw_all(v);       // call draw() for each element
        rotate_all(v, 45); //call rotate(45) for each element
    }                      // all Shapes implicitly destroyed