#include <ostream>

template<typename T>
    class Array {
protected:
    T* data;
    size_t size;
    size_t capacity;

    /**
     * @brief Deep copy other array into this array 
     * 
     * @param other Array to deep copy from
     */
    void deepCopy(const Array& other);
public:

    /**
     * @brief Array constructor 
     * 
     * @tparam Array type 
     * @param cap initial capacity of array  
     */
    Array(size_t cap = 16);


    /**
     * @brief Copy constructor 
     * 
     * @param other array to construct from
     */
    Array(const Array& other);
    

    /**
     * @brief Assignment operator 
     * 
     * @param other Array to assign from
     * @return Array& 
     */
    Array& operator=(const Array& other);


    /**
     * @brief lvalue random access operator 
     * 
     * @param idx index 
     * @return T& | reference to stored data 
     */
    T& operator[](size_t idx);


    /**
     * @brief const lvalue random access operator 
     * 
     * @param idx index 
     * @return const T& | const reference to stored data 
     */
    const T& operator[](size_t idx) const;
    

    /**
     * @brief insert element into array at index 
     * 
     * @param elem element
     * @param idx index
     */
    void insert(const T& elem, size_t idx);

    /**
     * @brief insert element into array at end 
     * 
     * @param elem element 
     */
    void insert(const T& elem);

    /**
     * @brief remove element at index 
     * 
     * @param idx index
     */
    void remove(size_t idx);

    /**
     * @brief remove element at end  
     * 
     */
    void remove();
 
    /**
     * @brief Array destructor
     * 
     */
    virtual ~Array();
};


/**
 * @brief print to ostream operator 
 * 
 * @tparam T   type of array object 
 * @return std::ostream& 
 */
template<typename T>
std::ostream& operator<<(std::ostream&, Array<T>);
