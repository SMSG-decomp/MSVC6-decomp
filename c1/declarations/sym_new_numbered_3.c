void __cdecl sym_new_numbered_3(c1_symbol *sym)

{
  void *name;
  c1_symbol *pcVar1;
  uint uVar2;
  
  if ((g_opt_Zi != '\0') && ((sym->x2c).references == (c1_symbol_cell *)0x0)) {
    name = debug_segment_symbol_name(sym);
    pcVar1 = sym_take_free_record(10,name,0);
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = arena_alloc(g_arenas,g_symbol_size_table[10] + 3 & 0xfffffffc);
      if (pcVar1 == (c1_symbol *)0x0) {
        pcVar1 = (c1_symbol *)0x0;
      }
      else {
        pcVar1 = sym_init_kind(pcVar1,'\n',name,0);
      }
    }
    (sym->x2c).debug_object = pcVar1;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar2 = pcVar1->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar1->entity = uVar2 & 0xffffff ^ pcVar1->entity;
    pcVar1->type = sym->type;
    pcVar1->storage = pcVar1->storage & 0xf8 ^ 2;
    pcVar1->storage = pcVar1->storage | 0x40;
    pcVar1->flags21 = pcVar1->flags21 | 0x80;
    pcVar1->flags4 = pcVar1->flags4 | 0x80;
    pcVar1->flags1 = pcVar1->flags1 | 0x41;
    pcVar1->flags3 = pcVar1->flags3 | 4;
    sym_mark_referenced(pcVar1);
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,pcVar1);
  }
  return;
}

