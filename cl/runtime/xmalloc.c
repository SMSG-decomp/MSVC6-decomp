void * __cdecl xmalloc(size_t n)

{
  void *p;
  
  p = malloc(n);
  if (p == (void *)0x0) {
    cl_error(0);
  }
  return p;
}

