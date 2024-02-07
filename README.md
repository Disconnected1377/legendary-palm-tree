# legendary-palm-tree
Linked List Code In C Programing Language
Integer data can be inserted in first or last and the deletion operation can be performed from first or last.
display option will display the current data present in the linked list.

Below points may help you to understand the code: 
1. the stdlib.h header file is included for memory allocation functions (the memory size isn't known at compile time).
2. malloc is used for dynamic memmory allocation.
3. Here's how malloc works:

    Requesting memory: You call malloc with the size of the memory block you want to allocate, in bytes. The size parameter must be of type size_t, which is an unsigned integer that can hold the size of the largest object in memory.

    Finding a suitable block: The C library attempts to find a block of unused memory on the heap that's at least the size you requested. This process often involves merging smaller free blocks to create a larger contiguous block.

    Allocation success: If malloc finds a suitable block, it returns a pointer to the beginning of the allocated memory. This pointer is of type void*, meaning it can be cast to any other pointer type (e.g., int*, char*) based on how you intend to use the memory.

    Allocation failure: If no suitable block is available, malloc returns NULL, indicating that the memory allocation failed. You should check the return value of malloc to handle this case gracefully, as using a dangling pointer (a pointer that doesn't point to valid memory) can lead to program crashes or security vulnerabilities.

    Using the allocated memory: You can now use the returned pointer to access and manipulate the allocated memory. Remember that malloc doesn't initialize the memory, so you need to set its values explicitly before using it.

    Deallocating memory: When you're finished using the allocated memory, it's crucial to deallocate it using the free function. This returns the memory block to the heap, preventing memory leaks and making it available for other allocations. Passing an invalid pointer or a pointer obtained from a different allocation to free is undefined behavior and can lead to serious problems.
