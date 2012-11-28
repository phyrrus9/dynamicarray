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

template <class at> dynamicarray<at>::dynamicarray()
{
    data = new at[1];
    size = 1;
}

template <class at> dynamicarray<at>::dynamicarray(const dynamicarray &old)
{
    data = new at[1];
    size = 1;
    for (int i = 0; i < old.getsize(); i++)
    {
        set(old.get(i), i);
    }
}

template <class at> dynamicarray<at>::dynamicarray(int initsize)
{
    data = new at[initsize];
    size = initsize;
}

template <class at> dynamicarray<at>::dynamicarray(at *initdata, int initsize)
{
    data = new at[initsize];
    size = initsize;
    for (int i = 0; i < size; i++)
    {
        data[i] = initdata[i];
    }
}

template <class T> void dynamicarray<T>::set(T din, int position)
{
    if (position > size)
    {
        T * temp;
        size = position;
        temp = new T[position + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i]; //copy old data
        }
        for (int i = size; i < position; i++)
        {
            data[i] = 0; //zero new fields
        }
        //cout << "setting [" << position << "] to " << din << endl;
        temp[position] = din; //set data
        delete[] data; //prevent a memory leak
        data = temp; //pointer copy
    }
    else
    {
        data[position] = din;
    }
}

template <class T> void dynamicarray<T>::set(T din)
{
    data[size] = din;
}

template <class T> T dynamicarray<T>::get(int position)
{
        return data[position + 1];
}

template <class T> T dynamicarray<T>::get(void)
{
    return data[size];
}

template <class T> int dynamicarray<T>::getsize(void)
{
    return size;
}

template <class T> void dynamicarray<T>::grow(int newsize)
{
    T *temp = new T[newsize];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    for (int i = size; i < newsize; i++)
    {
        temp[i] = 0;
    }
    size = newsize;
    delete[] data;
    data = temp;
}

template <class T> void dynamicarray<T>::shrink(int newsize)
{
    size = newsize;
    T *temp = new T[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}