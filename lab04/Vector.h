template <class T,class = allocator<T> >
class Vector
{
public:
   typedef T * iterator;
   Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const T & initial);
   Vector(const Vector<T> & v);           // copy constructor
   ~Vector();
   unsigned int capacity() const;         // return capacity of vector (in elements)
   unsigned int size() const;             // return the number of elements in the vector
   bool empty() const;
   iterator begin();                      // return an iterator pointing to the first element
   iterator end();                        // return an iterator pointing to one past the last element
   T & front();                           // return a reference to the first element
   T & back();                            // return a reference to the last element
   void push_back(const T & value);       // add a new element
   void pop_back();                       // remove the last element
   void reserve(unsigned int capacity);   // adjust capacity
   void resize(unsigned int size);        // adjust size
   T & operator[](unsigned int index);    // return reference to numbered element
   Vector<T> & operator=(const Vector<T> &);
private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};
// Beginning of implementation
template<class T>
Vector<T>::Vector()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}
template<class T>
Vector<T>::~Vector()
{
    my_size = 0;
    delete[] buffer;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];  
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];  
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template<class T>
void Vector<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
    delete[] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T [my_capacity];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];

    return *this;
}

template<class T>
void Vector<T>::push_back(const T & v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity +5); // increase 5 more memory locations

    buffer [my_size++] = v; 
}
template<class T>
void Vector<T>::pop_back()
{
    my_size--;
}
template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
    if(buffer == 0){
        my_size = 0;
        my_capacity = 0;
    }    
    T * Newbuffer = new T [capacity];
    assert(Newbuffer);
    unsigned int l_Size;
    if (capacity < my_size)
        l_Size = capacity;
    else 
        l_Size = my_size;

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}
template<class T>
unsigned int Vector<T>::size()const
{
    return my_size;
}
template<class T>
unsigned int Vector<T>::capacity()const
{
    return my_capacity;
}
template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}
template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}
template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + size();
}
template<class T>
T& Vector<T>::front()
{
    return buffer[0];
}
template<class T>
T& Vector<T>::back()
{
    return buffer[my_size - 1];
}