c1_u8 * __cdecl arena_or_heap_object_new(int size,char in_arena,c1_arena *a)

{
  c1_u8 *pcVar1;
  
  if (in_arena == '\x01') {
    pcVar1 = a->cur;
    a->cur = pcVar1 + size;
    if (a->end < pcVar1 + size) {
      arena_grow(a);
    }
    *(c1_arena **)pcVar1 = a;
    pcVar1[4] = '\x01';
    return pcVar1;
  }
  pcVar1 = mem_xmalloc(size);
  *(c1_arena **)pcVar1 = a;
  pcVar1[4] = in_arena;
  return pcVar1;
}

