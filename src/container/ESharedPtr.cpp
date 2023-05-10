/**
 * @file eshared_ptr.cpp
 * @brief Implementation of the ESharedPtr class.
 */

#include "container/ESharedPtr.h"

#include <stdlib.h>

/**
 * Default constructor.
 * Initializes the pointer to NULL and the reference count to zero.
 */
ESharedPtr::ESharedPtr() : 
    m_ptr(NULL),
    m_count(NULL),
    m_lock(NULL),
    m_deleter(NULL)
{}

/**
 * Constructor.
 * Initializes the pointer to the given value and the reference count to one.
 * @param ptr The underlying data pointer.
 */
ESharedPtr::ESharedPtr(void* ptr, void (*deleter)(void*)) :
    m_ptr(ptr),
    m_count(new unsigned int(1)),
    m_lock(new bool(false)),
    m_deleter(deleter)
{}

/**
 * Copy constructor.
 * Increments the reference count of the underlying data.
 * @param other The other ESharedPtr object to copy.
 */
ESharedPtr::ESharedPtr(const ESharedPtr& other) :
    m_ptr(other.m_ptr),
    m_count(other.m_count),
    m_lock(other.m_lock),
    m_deleter(other.m_deleter)
{
    increment();
}

/**
 * Destructor.
 * Decrements the reference count of the underlying data and frees it if necessary.
 */
ESharedPtr::~ESharedPtr()
{
    decrement();
}

/**
 * Assignment operator.
 * Decrements the reference count of the old underlying data and
 * increments the reference count of the new underlying data.
 * @param other The other ESharedPtr object to copy.
 * @return The updated ESharedPtr object.
 */
ESharedPtr& ESharedPtr::operator=(const ESharedPtr& other)
{
    if (this != &other) {
        decrement();
        m_ptr = other.m_ptr;
        m_count = other.m_count;
        m_lock = other.m_lock;
        m_deleter = other.m_deleter;
        increment();
    }
    return *this;
}

/**
 * Dereference operator.
 * @return The underlying data pointer.
 */
void* ESharedPtr::operator*() const
{
    return m_ptr;
}

/**
 * Pointer operator.
 * @return The underlying data pointer.
 */
void* ESharedPtr::operator->() const
{
    return m_ptr;
}

/**
 * Increments the reference count.
 */
void ESharedPtr::increment()
{
    while (!acquire_lock()) {
        // Spin while lock is held by another thread.
    }
    ++(*m_count); // Increment reference count.
    release_lock();
}

/**
 * Decrements the reference count and frees the underlying data if necessary.
 */
void ESharedPtr::decrement()
{
    while (!acquire_lock()) {
        // Spin while lock is held by another thread.
    }
    if (--(*m_count) == 0) { // Decrement reference count and check if it becomes zero.
        if (m_deleter) {
            m_deleter(m_ptr);
        } else {
            free(m_ptr);
        }
        delete m_count;
        m_count = NULL;
        // delete m_lock;
        // m_lock = NULL;
        m_ptr = NULL;
    }
    release_lock();
}

/**
 * Attempts to acquire the spin-lock.
 * @return true if the lock was acquired successfully, false otherwise.
 */
bool ESharedPtr::acquire_lock()
{
    if (*m_lock) {
        return false; // Lock already held by another thread.
    }
    *m_lock = true; // Acquire lock.
    return true;
}

/**
 * Releases the spin-lock.
 */
void ESharedPtr::release_lock()
{
    *m_lock = false; // Release lock.
}
