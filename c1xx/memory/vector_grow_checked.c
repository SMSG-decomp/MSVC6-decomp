void * __cdecl vector_grow_checked(c1_symbol_vector *v)

{
  c1_u16 count;
  c1_u16 cVar1;
  uint new_size;
  uint src_size;
  void *pvVar2;
  
  count = v->capacity;
  cVar1 = ((short)count >> 2) + 1 + count;
  v->capacity = cVar1;
  if ((short)count < (short)cVar1) {
    new_size = counted_array_size(v->capacity);
    src_size = counted_array_size(count);
    pvVar2 = arena_alloc_copy_bytes(g_arenas,v,src_size,new_size);
    return pvVar2;
  }
  diag_fatal_simple(0xcc);
}

