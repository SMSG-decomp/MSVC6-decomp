c1_symbol * __cdecl decl_old_style_parameter_name(void *name)

{
  c1_symbol *pcVar1;
  uint uVar2;
  
  pcVar1 = arena_alloc(g_arenas + 2,g_symbol_size_table[0xb] + 3 & 0xfffffffc);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = (c1_symbol *)0x0;
  }
  else {
    pcVar1 = sym_init_kind(pcVar1,'\v',name,2);
  }
  pcVar1->type = g_type_int;
  if (g_next_entity_id < 0x7fffffff) {
    uVar2 = pcVar1->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar1->entity = uVar2 & 0xffffff ^ pcVar1->entity;
    pcVar1->flags3 = pcVar1->flags3 | 0x10;
    (*g_current_scope->current->vtbl->insert)(g_current_scope->current,pcVar1);
    return pcVar1;
  }
  diag_fatal_simple(0x37);
}

