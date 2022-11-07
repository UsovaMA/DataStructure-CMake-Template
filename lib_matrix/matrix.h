// Copyright 2022 Marina Usova

#ifndef LIB_MATRIX_MATRIX_H_
#define LIB_MATRIX_MATRIX_H_

#include <iostream>
#include <algorithm>
#include <utility>

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<class T>
class TDynamicVector {
 protected:
  size_t sz;
  T* pMem;

 public:
  explicit TDynamicVector(size_t size) : sz(size) {
    if (sz == 0)
      throw std::out_of_range("Vector size should be greater than zero");
    if (sz < 0 || sz >= MAX_VECTOR_SIZE)
        throw std::out_of_range("Out of bounds of vector size");
    pMem = new T[sz];
  }

  TDynamicVector(T* arr, size_t s) : sz(s) {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  explicit TDynamicVector(const TDynamicVector& v) {
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];
      }
  }

 // explicit TDynamicVector(TDynamicVector&& v) noexcept {
 //     sz = v.sz;
 //     pMem = new T[sz];
 //     for (int i = 0; i < sz; i++) {
 //         pMem[i] = v.pMem[i];
 //     }
 // }

  ~TDynamicVector() {
      delete[]pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v) {
    sz = v.sz;
    delete[]pMem;
    pMem = new T[sz](v.sz);
    for (int i = 0; i < sz; i++) {
        pMem[i] = v.pMem[i];
    }
    return *this;
  }

 // TDynamicVector& operator=(TDynamicVector&& v) noexcept {
 //     sz = v.sz;
 //     delete[]pMem;
 //     pMem = new T[v.sz];
 //     for (int i = 0; i < sz; i++) {
 //         pMem[i] = v.pMem[i];
 //     }
 //     return *this;
 // }

  size_t size() const noexcept { return sz; }

  // indexing

  T& operator[](size_t ind) {
      if (ind < 0 || ind >= sz)
      {
          throw std::out_of_range("Index out of size");
      }
      return pMem[ind];
  }

  const T& operator[](size_t ind) const {
      if (ind < 0 || ind >= sz)
      {
          throw std::out_of_range("Index out of size");
      }
      return pMem[ind];
  }

  // indexing with control

  T& at(size_t ind) {
      if (ind < 0 || ind >= sz)
      {
          throw std::out_of_range("Index out of size");
      }
      return pMem[ind];
  }

  const T& at(size_t ind) const {
      if (ind < 0 || ind >= sz)
      {
          throw std::out_of_range("Index out of size");
      }
      return pMem[ind];
  }

  // comparisons

  bool operator==(const TDynamicVector& v) const noexcept {
      if (sz != v.sz) return false;
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i])
              return false;
      }
      return true;
  }

  bool operator!=(const TDynamicVector& v) const noexcept {
      return !(*this == v);
  }

  // scalar operations

  TDynamicVector operator+(T val) {
      TDynamicVector<T> result(*this);
      for (int i = 0; i < sz; i++) {
          result.pMem[i] += val;
      }
      return result;
  }

  TDynamicVector operator-(double val) {
      TDynamicVector<T> result(*this);
      for (int i = 0; i < sz; i++) {
          result.pMem[i] -= val;
      }
      return result;

  }

  TDynamicVector operator*(double val) {
      TDynamicVector<T> result(*this);
      for (int i = 0; i < sz; i++)
          result.pMem[i] *= val;
      return result;
  }

  // vector operations

  TDynamicVector& operator+(const TDynamicVector& v);

  TDynamicVector& operator-(const TDynamicVector& v) {
      if (sz != v.sz) {
          throw std::logic_error("Can't deduct vectors with not equal sizes");
      }
      TDynamicVector temp(v);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = v.pMem[i] + pMem[i];
      }
      return temp;
  }

  T& operator*(const TDynamicVector& v) noexcept(noexcept(T())) {
      if (sz != v.sz) {
          throw std::logic_error("Can't deduct vectors with not equal sizes");
      }
      TDynamicVector temp(v);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = v.pMem[i] * pMem[i];
      }
      return temp;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // input / output


  friend std::istream& operator>>(std::istream& istr, TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i];
    return istr;
  }

  friend std::ostream& operator<<(std::ostream& ostr, const TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' ';
    return ostr;
  }
};
template <class t>
TDynamicVector<t>& TDynamicVector<t>::operator+(const TDynamicVector<t>& v) {
    if (sz != v.sz) {
        throw std::logic_error("Can't add vectors with not equal sizes");
    }
    TDynamicVector<t> temp(sz);
    for (int i = 0; i < sz; i++) {
        temp.pMem[i] = v.pMem[i] + pMem[i];
    }
    return temp;
}

template<class T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>> {
  //using TDynamicVector<TDynamicVector<T>>::pMem;
  //using TDynamicVector<TDynamicVector<T>>::sz;

  public:
  explicit TDynamicMatrix(size_t s)
    : TDynamicVector<TDynamicVector<T>>(s) {
      if (s < 0 || s > MAX_MATRIX_SIZE)
          throw std::out_of_range("Out of bounds of matrix size");
    }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;

  //Type-conversation constructor

  TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& m) :
      TDynamicVector<TDynamicVector<T>>(m) {}


  // comparison

  bool operator==(const TDynamicMatrix& m) const noexcept {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }

  // matrix-scalar operations

  TDynamicVector<T> operator*(const T& val) {
      return TDynamicVector<TDynamicVector<T>>::operator*(m);
  }

  // matrix-vector operations

  TDynamicVector<T> operator*(const TDynamicVector<T>& v) {
      return TDynamicVector <T<T>>:: operator*(m);
  }

  // matrix-matrix operations

  TDynamicMatrix operator+(const TDynamicMatrix& m);

  TDynamicMatrix operator-(const TDynamicMatrix& m) {
      return TDynamicVector<TDynamicVector<T>>::operator-(m);
  }

  TDynamicMatrix operator*(const TDynamicMatrix& m) {
      return TDynamicVector<TDynamicVector<T>>::operator*(m);
  }

  // input / output

  friend std::istream& operator>>(std::istream& istr, TDynamicMatrix& v) {
      for (int i = 0; i < v.sz; i++){
          istr >> v.pMem[i];
      }
      return istr;
  }

  friend std::ostream& operator<<(std::ostream& ostr, const TDynamicMatrix& v) {
      for (int i = 0; i < v.sz; i++) {
          ostr << v.pMem[i] << std::endl;
      }
      return ostr;
  }
};

template <class t>
TDynamicMatrix<t> TDynamicMatrix<t>::operator+(const TDynamicMatrix<t>& m) {
    return TDynamicVector<TDynamicVector<t>>::operator+(m);
}

#endif  // LIB_MATRIX_MATRIX_H_
