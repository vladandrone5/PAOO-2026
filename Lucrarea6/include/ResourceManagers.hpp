#pragma once
#include "Mutex.hpp"
#include <memory>
#include <iostream>
#include <cstring>

// ============================================================================
// Strategy 1: Prohibit Copying (Best for a Mutex Lock)
// ============================================================================
class LockNoCopy {
private:
    Mutex* mutexPtr;

public:
    explicit LockNoCopy(Mutex* pm) : mutexPtr(pm) {
        // TODO: Acquire the resource using lock(mutexPtr)
        lock(mutexPtr);
    }

    ~LockNoCopy() {
        // TODO: Release the resource using unlock(mutexPtr)
        unlock(mutexPtr);
    }

    // TODO: Explicitly delete the copy constructor and copy assignment operator
    LockNoCopy(const LockNoCopy&) = delete;
    LockNoCopy& operator=(const LockNoCopy&) = delete;
};

// ============================================================================
// Strategy 2: Reference-Count the Underlying Resource (shared_ptr + custom deleter)
// ============================================================================
class LockRefCount {
private:
    std::shared_ptr<Mutex> mutexPtr;

public:
    explicit LockRefCount(Mutex* pm)
        // TODO: Initialize mutexPtr with pm and pass `unlock` as the custom deleter
        : mutexPtr(pm, lock)
    {
        // TODO: Call lock(mutexPtr.get()) to acquire the mutex
        lock(mutexPtr.get());
    }

    // Note: Compiler-generated destructor, copy constructor, and copy assignment
    // will automatically manage the reference count and call `unlock` when count hits 0.
    
    long getRefCount() const {
        // TODO: Return mutexPtr.use_count()
        return mutexPtr.use_count();
        //return 0;
    }
};

// ============================================================================
// Strategy 3: Deep Copy the Underlying Resource (Fits memory, not a Mutex)
// ============================================================================
class BufferDeepCopy {
private:
    char* data;
    size_t size;

public:
    explicit BufferDeepCopy(const char* str) {
        // TODO: Allocate memory for `data` and copy `str` into it
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
    }

    ~BufferDeepCopy() {
        // TODO: Free `data` using delete[]
        delete[] data;
    }

    // TODO: Implement copy constructor (allocate new memory and copy contents)
    BufferDeepCopy(const BufferDeepCopy& rhs)
        : size(rhs.size), data(new char[rhs.size + 1])
    {
        std::strcpy(data, rhs.data);
    }

    // TODO: Implement copy assignment operator (handle self-assignment / exception safety)
    BufferDeepCopy& operator=(const BufferDeepCopy& rhs) {

        BufferDeepCopy temp(rhs);
        std::swap(data, temp.data);
        std::swap(size, temp.size);

        return *this;
    }

    void print() const {
        if (data) {
            std::cout << "[Buffer] \" " << data << " \" (addr: " << static_cast<const void*>(data) << ")\n"; 
        }
    }
};

// ============================================================================
// Strategy 4: Transfer Ownership (Move semantics, like unique_ptr)
// ============================================================================
class LockTransfer {
private:
    Mutex* mutexPtr;

public:
    explicit LockTransfer(Mutex* pm) : mutexPtr(pm) {
        // TODO: Acquire the resource using lock(mutexPtr)
        lock(mutexPtr);
    }

    ~LockTransfer() {
        // TODO: Only unlock if mutexPtr != nullptr
        if(mutexPtr) {
            unlock(mutexPtr);
        }
    }

    // Prohibit copying
    LockTransfer(const LockTransfer&) = delete;
    LockTransfer& operator=(const LockTransfer&) = delete;

    // TODO: Implement move constructor (steal rhs.mutexPtr and set rhs.mutexPtr = nullptr)
    LockTransfer(LockTransfer&& rhs) noexcept : mutexPtr(rhs.mutexPtr) {
        rhs.mutexPtr = nullptr;
    }

    // TODO: Implement move assignment operator (release current if owned, steal rhs, null rhs)
    LockTransfer& operator=(LockTransfer&& rhs) noexcept {
        if(this != &rhs) {
            if(mutexPtr) {
                unlock(mutexPtr);
            }
            mutexPtr = rhs.mutexPtr;
            rhs.mutexPtr = nullptr;
        }

        return *this;
    }
};