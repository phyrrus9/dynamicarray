/*
 dynamicarray template class copyright © 2012 phyrrus9
 This class is just a simple implementation of a dynamic
 vector class, that takes in all data types
 */
template <class T> class dynamicarray
{
    T *data;
    int size;
public:
    dynamicarray();
    dynamicarray(const dynamicarray &old);
    dynamicarray(int initsize);
    dynamicarray(T *initdata, int initsize);
    T get(int position);
    T get(void); //get last position
    int getsize(void);
    void set(T din, int position);
    void set(T din); //set to last position
    void grow(int newsize);
    void shrink(int newsize);
};
