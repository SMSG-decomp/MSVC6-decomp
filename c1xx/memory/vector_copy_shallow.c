c1_vector * __cdecl vector_copy_shallow(c1_vector *src,int arena)

{
  c1_vector *pcVar1;
  
  pcVar1 = vector_copy_shallow_reserve(src,1,arena);
  return pcVar1;
}

