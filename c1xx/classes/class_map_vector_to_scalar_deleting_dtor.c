void __cdecl class_map_vector_to_scalar_deleting_dtor(c1_symbol *vdd,c1_symbol *sdd)

{
  if (g_vector_to_scalar_deleting_dtor_table == (c1_symtab *)0x0) {
    g_vector_to_scalar_deleting_dtor_table = symtab_new(0x1f,0,0,0,'\x01','\x01');
  }
  symtab_insert(g_vector_to_scalar_deleting_dtor_table,vdd,sdd);
  return;
}

