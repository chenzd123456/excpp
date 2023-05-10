/**
 * @file eshared_ptr.h
 * @brief Reference-counted pointer implementation.
 */

#ifndef ESHARED_PTR_H
#define ESHARED_PTR_H

/**
 * A simple reference-counted pointer implementation.
 *
 * This implementation is thread-safe and uses a spin-lock to ensure
 * atomic operations.
 *
 * In order to avoid the use of templates and improve portability,
 * this implementation uses void* as the underlying data pointer type.
 */
class ESharedPtr {
  public:
    /**
     * Default constructor.
     * Initializes the pointer to NULL and the reference count to zero.
     */
    ESharedPtr();

    /**
     * Constructor.
     * Initializes the pointer to the given value and the reference count to
     * one.
     * @param ptr The underlying data pointer.
     */
    ESharedPtr(void *ptr, void (*deleter)(void *));

    /**
     * Copy constructor.
     * Increments the reference count of the underlying data.
     * @param other The other ESharedPtr object to copy.
     */
    ESharedPtr(const ESharedPtr &other);

    /**
     * Destructor.
     * Decrements the reference count of the underlying data and frees it if
     * necessary.
     */
    ~ESharedPtr();

    /**
     * Assignment operator.
     * Decrements the reference count of the old underlying data and
     * increments the reference count of the new underlying data.
     * @param other The other ESharedPtr object to copy.
     * @return The updated ESharedPtr object.
     */
    ESharedPtr &operator=(const ESharedPtr &other);

    /**
     * Dereference operator.
     * @return The underlying data pointer.
     */
    void *operator*() const;

    /**
     * Pointer operator.
     * @return The underlying data pointer.
     */
    void *operator->() const;

  private:
    void *m_ptr;               // The underlying data pointer.
    unsigned int *m_count;     // The reference count.
    bool *m_lock;              // The spin-lock.
    void (*m_deleter)(void *); // Function pointer for object deletion.

    /**
     * Increments the reference count.
     */
    void increment();

    /**
     * Decrements the reference count and frees the underlying data if
     * necessary.
     */
    void decrement();

    /**
     * Attempts to acquire the spin-lock.
     * @return true if the lock was acquired successfully, false otherwise.
     */
    bool acquire_lock();

    /**
     * Releases the spin-lock.
     */
    void release_lock();
};

#endif // ESHARED_PTR_H
