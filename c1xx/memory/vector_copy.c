c1_vector * __cdecl vector_copy(c1_vector *src,int arena,void *copy_fn)

{
  c1_vector *v;
  void *item;
  short sVar1;
  
  if ((src != (c1_vector *)0x0) && (src->count != 0)) {
    v = vector_new(src->count,arena);
    for (sVar1 = 0; (int)sVar1 < (int)(uint)src->count; sVar1 = sVar1 + 1) {
      item = (void *)(*copy_fn)(src->data[sVar1],arena);
      vector_push(v,item);
    }
    return v;
  }
  return (c1_vector *)0x0;
}

