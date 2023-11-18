#ifndef DYNAMICCONTAINER_H
#define DYNAMICCONTAINER_H

#include <algorithm>
#include <initializer_list>
#include <iostream>
template <typename T> class DynamicContainer {
public:
  DynamicContainer();
  DynamicContainer(std::initializer_list<T> values);
  ~DynamicContainer();

  void push_back(const T &value);
  void push_front(const T &value);
  void insert(const T &value, size_t index);
  T &operator[](size_t index);
  DynamicContainer &operator=(const DynamicContainer &other);

  size_t find(T &value) ;

  bool remove(const T &value);
  void remove_at(size_t index);

  void sort();
  template <typename Compare> void sort(Compare comparator);

  void reverse();

  void merge(const DynamicContainer<T> &other);

  void resize(size_t new_size);
  size_t size() const;
  size_t capacity() const;
  //
  // class Iterator {
  // public:
  //   Iterator(T *ptr) : ptr(ptr) {}
  //   T &operator*() { return *ptr; }
  //   Iterator &operator++() {
  //     ++ptr;
  //     return *this;
  //   }
  //   Iterator operator++(int) {
  //     Iterator temp = *this;
  //     ++ptr;
  //     return temp;
  //   }
  //   Iterator &operator--() {
  //     --ptr;
  //     return *this;
  //   }
  //   Iterator operator--(int) {
  //     Iterator temp = *this;
  //     --ptr;
  //     return temp;
  //   }
  //   bool operator==(const Iterator &other) const { return ptr == other.ptr; }
  //   bool operator!=(const Iterator &other) const { return ptr != other.ptr; }
  //
  // private:
  //   T *ptr;
  // };
  //
  // Iterator begin() { return Iterator(elements); }
  // Iterator end() { return Iterator(elements + _size); }
  //
  T *begin() const{ return (elements); };
  T *end() const{ return (elements+_size); };
  T *back() const{ return (elements+_size-1); };

private:
  T *elements;
  size_t _size;
  size_t _capacity;

  void resize_internal();
  void resize_internal(size_t new_size);
};

template <typename T>
DynamicContainer<T>::DynamicContainer()
    : elements(nullptr), _size(0), _capacity(0) {}

template <typename T> DynamicContainer<T>::~DynamicContainer() {
  delete[] elements;
}

template <typename T>
DynamicContainer<T>::DynamicContainer(std::initializer_list<T> values)
    : elements(nullptr), _size(0), _capacity(0) {
    for (const T& value : values) {
        push_back(value);
    }
}
template <typename T> void DynamicContainer<T>::push_back(const T &value) {
  if (_size == _capacity) {
    resize_internal();
  }
  elements[_size++] = value;
}

template <typename T> void DynamicContainer<T>::push_front(const T &value) {
  insert(value, 0);
}

template <typename T>
void DynamicContainer<T>::insert(const T &value, size_t index) {
  if (index > _size) {
    throw std::out_of_range("Index out of range");
  }
  if (_size == _capacity) {
    resize_internal();
  }
  for (size_t i = _size; i > index; --i) {
    elements[i] = elements[i - 1];
  }
  elements[index] = value;
  _size++;
}

template <typename T>
T& DynamicContainer<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
template <typename T>
DynamicContainer<T>& DynamicContainer<T>::operator=(const DynamicContainer<T>& other) {
    if (this != &other) {  
        delete[] elements;

        _size = other._size;
        _capacity = other._capacity;

        elements = new T[_capacity];

        for (size_t i = 0; i < _size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T> size_t DynamicContainer<T>::find( T &value){
  for (size_t i = 0; i < _size; ++i) {
    if (elements[i] == value) {
      return i;
    }
  }
  return -1;
}


template <typename T> bool DynamicContainer<T>::remove(const T& value) {
    for (size_t i = 0; i < _size; ++i) {
        if (elements[i] == value) {
            remove_at(i);
            return 1;
        }
    }
    return 0;
}


template <typename T> void DynamicContainer<T>::remove_at(size_t index) {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  for (size_t i = index; i < _size - 1; ++i) {
    elements[i] = elements[i + 1];
  }
  _size--;
}

template <typename T>
template <typename Compare>
void DynamicContainer<T>::sort(Compare comparator) {
    std::sort(elements, elements + _size, comparator);
}

template <typename T>
void DynamicContainer<T>::sort() {
    std::sort(elements, elements + _size);
}


template <typename T>
void DynamicContainer<T>::reverse() {
    std::reverse(elements, elements + _size);
}

template <typename T>
void DynamicContainer<T>::merge(const DynamicContainer<T>& other) {
    size_t new_size = _size + other._size;
    if (new_size > _capacity) {
        resize_internal(new_size);
    }

    for (size_t i = 0; i < other._size; ++i) {
        elements[_size + i] = other.elements[i];
    }

    _size = new_size;
}


template <typename T>
void DynamicContainer<T>::resize_internal() {
    size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
    T* new_elements = new T[new_capacity];
    for (size_t i = 0; i < _size; ++i) {
        new_elements[i] = elements[i];
    }
    delete[] elements;
    elements = new_elements;
    _capacity = new_capacity;
}

template <typename T>
void DynamicContainer<T>::resize_internal(size_t new_capacity) {
    T* new_elements = new T[new_capacity];
    for (size_t i = 0; i < _size; ++i) {
        new_elements[i] = elements[i];
    }
    delete[] elements;
    elements = new_elements;
    _capacity = new_capacity;
}
template <typename T>
void DynamicContainer<T>::resize(size_t new_size) {
    if (new_size < _size) {
        _size = new_size;
    } else if (new_size > _capacity) {
        T* new_elements = new T[new_size];
        for (size_t i = 0; i < _size; ++i) {
            new_elements[i] = elements[i];
        }
        delete[] elements;
        elements = new_elements;
        _capacity = new_size;
    }
}
template <typename T>
size_t DynamicContainer<T>::size() const {
    return _size;
}

template <typename T>
size_t DynamicContainer<T>::capacity() const {
    return _capacity;
}
#endif // DYNAMICCONTAINER_H
       
