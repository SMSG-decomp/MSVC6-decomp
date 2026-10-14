void __cdecl vector_for_each(c1_vector *vec,void *callback)

{
  short sVar1;
  
  if (vec != (c1_vector *)0x0) {
    for (sVar1 = 0; (int)sVar1 < (int)(uint)vec->count; sVar1 = sVar1 + 1) {
      (*callback)(vec->data[sVar1]);
    }
  }
  return;
}

