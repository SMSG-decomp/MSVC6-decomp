c1_symbol * __cdecl sym_segment_record(c1_symbol *sym)

{
  c1_symbol *pcVar1;
  
  pcVar1 = symtab_lookup(g_segment_record_table,(void *)(sym->entity & 0xffffff));
  return pcVar1;
}

