void __cdecl symtab_15ec_insert_by_id(c1_symbol *sym,void *value)

{
  if (g_debug_type_by_id_table == (c1_symtab *)0x0) {
    g_debug_type_by_id_table = symtab_new(0x1f,0,3,2,'\0','\0');
  }
  symtab_insert(g_debug_type_by_id_table,(void *)(sym->entity & 0xffffff),value);
  return;
}

