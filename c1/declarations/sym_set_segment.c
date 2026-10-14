void __cdecl sym_set_segment(c1_symbol *sym,void *value)

{
  uint uVar1;
  
  if ((sym->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar1 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar1 & 0xffffff ^ sym->entity;
  }
  if (g_segment_record_table == (fe_symtab *)0x0) {
    g_segment_record_table = symtab_new(0x1f,0,3,2,'\0','\x01');
  }
  symtab_insert(g_segment_record_table,(void *)(sym->entity & 0xffffff),value);
  sym->flags23 = sym->flags23 | 1;
  return;
}

