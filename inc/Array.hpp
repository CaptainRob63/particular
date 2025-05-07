#include <ostream>

template<typename T>
    class Array {
protected:
    T* data;
    size_t size;
    size_t capacity;

    void deepCopy(const Array&);
public:
    Array(size_t s = 1);
    Array(const Array&);
    
    Array& operator=(const Array&);
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
    
    void insert(T* elem, size_t idx);
    void remove(size_t idx);
    virtual ~Array();
};
template<typename T>
std::ostream& operator<<(std::ostream&, Array<T>);
