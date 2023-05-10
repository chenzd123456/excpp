#include "gtest/gtest.h"

#include "container/ESharedPtr.h"

#include <memory.h>

void deleter(void* ptr) {
    free(ptr);
}

TEST(ESharedPtr, test1) {
    
    ESharedPtr a(malloc(5), deleter);
}