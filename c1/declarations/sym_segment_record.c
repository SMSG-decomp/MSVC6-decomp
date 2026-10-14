void * __cdecl sym_segment_record(c1_symbol *sym)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_segment_record_table,(void *)(sym->entity & 0xffffff));
  return pvVar1;
}

