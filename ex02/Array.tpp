template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n) {
    _data = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size) {
    _data = (_size ? new T[_size] : NULL);
    for (unsigned int i = 0; i < _size; ++i)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        T* newData = (other._size ? new T[other._size] : NULL);
        for (unsigned int i = 0; i < other._size; ++i)
            newData[i] = other._data[i];

        delete[] _data;
        _data = newData;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Array: index out of range");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Array: index out of range");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}
