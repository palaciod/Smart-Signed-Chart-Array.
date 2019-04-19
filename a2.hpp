/***
 *  File: a2.hpp
 *  Author: Daniel Palacio <dpalacio@buffalo.edu>
 */

#ifndef A2_HPP
#define A2_HPP

#include <algorithm>

using namespace std;
class sorted_sc_array {
public:
    sorted_sc_array() : size_(0), ptr_(nullptr) { }

    ~sorted_sc_array() { delete[] ptr_; }

    sorted_sc_array(const sorted_sc_array& A){

    size_ = A.size_;
    cap = A.cap;
    ptr_ = new signed char [cap];
    copy(A.ptr_,A.ptr_+size_,ptr_);
    }
    /*
    * This method handles the equal sign operator, which handles a deep copy of
    * the contents of one smart array to another.
    */
    sorted_sc_array& operator=(const sorted_sc_array& A){
      if(this == &A){
        //delete[] ptr_;
        return *this;
      }
        delete[] ptr_;
       size_ = A.size_;
       cap = A.cap;

     if(size_!=0){
       ptr_ = new signed char[cap];
       copy(A.ptr_,A.ptr_+size_,ptr_);
     }
     return *this;
    }

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const { return size_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const {
     sort(ptr_,ptr_+size_);
      return ptr_;
      delete[] ptr_;
    }


    /**
    * Method insert() is the powerhouse of the class. Its purpose is to take a signed char and insert
    * it into the array while ensuring that at the end of the array is sorted in ascending order.
    * Each time a new element is inserted to the array, once insert completes the array must be in
    * sorted state.
    */
    void insert(signed char c){
      if(size_==0){ptr_ = new signed char[cap];}

    ptr_[size_]=c;
    size_++;
    if(size_==cap-1){
      cap=cap*2;
      signed char* temp = new signed char[cap];
      copy(ptr_,ptr_+size_,temp);
      delete[] ptr_;
      ptr_=temp;
    }



    }


private:
    int cap=4096/ sizeof ptr_;
    int size_;         // size of the array
    signed char* ptr_; // pointer to the array

}; // class sorted_sc_array

#endif // A2_HPP
