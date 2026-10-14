c1_symbol_vector * __cdecl vector_grow_checked(c1_symbol_vector *v)

{
  c1_u16 count;
  c1_u16 cVar1;
  uint new_size;
  uint src_size;
  c1_symbol_vector *pcVar2;
  
  count = v->capacity;
  cVar1 = ((short)count >> 2) + 1 + count;
  v->capacity = cVar1;
  if ((short)cVar1 <= (short)count) {
    diag_fatal_simple(0xcc);
  }
  new_size = counted_array_size(v->capacity);
  src_size = counted_array_size(count);
  pcVar2 = arena_alloc_copy_bytes(g_arenas,v,src_size,new_size);
  return pcVar2;
}

