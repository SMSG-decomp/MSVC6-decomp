c1_vtable_vector * __cdecl class_vtable_vector_copy(c1_vtable_vector *src,int arena)

{
  c1_vtable_vector *pcVar1;
  
  pcVar1 = (c1_vtable_vector *)vector_copy((c1_vector *)src,arena,class_vtable_record_copy);
  return pcVar1;
}

