void * __cdecl class_scalar_deleting_dtor_of(c1_symbol *vdd)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_vector_to_scalar_deleting_dtor_table,vdd);
  return pvVar1;
}

