#include "kheap.h"
#include "heap.h"
#include "CONFIG.h"
#include "kernel.h"

struct  heap kernel_heap;
struct heap_table kernel_heap_table;

void kheap_init()
{
   int total_table_entries = OXYOS_HEAP_SIZE_BYTES / OXYOS_HEAP_BLOCK_SIZE;
   kernel_heap_table.entries = (HEAP_BLOCK_TABLE_ENTRY*)(OXYOX_HEAP_TABLE_ADRESS);
   kernel_heap_table.total = total_table_entries;

   void* end = (void*)(OXYOS_HEAP_ADDRESS + OXYOS_HEAP_SIZE_BYTES);
   int res = heap_create(&kernel_heap, (void*)(OXYOS_HEAP_ADDRESS), end, &kernel_heap_table);

   if (res < 0)
   {
       print("Failed to create Heap \n");
   }

}

void* kmalloc(size_t size)
{
    return heap_malloc(&kernel_heap, size);
}

void kfeee(void* ptr)
{
    heap_free(&kernel_heap_table, ptr);
}