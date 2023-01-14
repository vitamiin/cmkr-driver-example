// from pavel's windows kernel programming
namespace kstd {
  template <typename T = void>
  struct unique_ptr {
    unique_ptr(T* p = nullptr) : _p(p) {}
    
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    
    unique_ptr(unique_ptr&& other) : _p(other.p) {
      other._p = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other){
      if (&other != this){
        Release();
        _p = other._p;
        other._p = nullptr;
      }

      return *this;
    }

    ~unique_ptr() {
      Release();
    }

    operator bool() const {
      return _p != nullptr;
    }
    
    T* operator->() const {
      return _p;
    }

    T& operator*() const {
      return *_p;
    }

    void Release() {
      if (_p)
        ::ExFreePool(_p);
    }

private:
    T* _p;
  };
};