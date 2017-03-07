#include <cublas_v2.h>
#include <cusparse.h>
void MemAdviseReadOnly(const void *ptr, int device);
void MemAdviseUnSetReadOnly(const void *ptr, int device);
void MemAdviseSetPrefLocDevice(const void *ptr, int device);
void MemAdviseSetPrefLocHost(const void *ptr);
void MemPrefetch(const void *ptr,int device,cudaStream_t stream);
void MemPrefetchForce(const void *ptr,int device,cudaStream_t stream);
void MemPrefetchReadOnly(const void *ptr,int device,cudaStream_t stream);
cublasHandle_t getCublasHandle();
cusparseHandle_t getCusparseHandle();
void hypreGPUInit();
typedef struct node {
  const void *ptr;
  size_t size;
  struct node *next;
} node;

size_t mempushc(const void *ptr, size_t size, int action);
node *memfind(node *head, const void *ptr);
void memdel(node **head, node *found);
void meminsert(node **head, const void *ptr,size_t size);
void printlist(node *head);
