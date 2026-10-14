void __cdecl func_emit_function_symbol(void)

{
  int iVar1;
  c1_sym_link *pcVar2;
  uint uVar3;
  
  iVar1 = g_macro_text_pending;
  g_macro_text_pending = 0;
  (*g_il_emitter->vtbl->begin_block)();
  if ((g_current_function->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar3 = g_current_function->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    g_current_function->entity = uVar3 & 0xffffff ^ g_current_function->entity;
  }
  (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,g_current_function);
  (*g_il_emitter->vtbl->set_owner)((int)g_current_function);
  g_macro_text_pending = iVar1;
  if (g_function_parameter_scope == (c1_sym_list *)0x0) {
    pcVar2 = (c1_sym_link *)0x0;
  }
  else {
    pcVar2 = g_function_parameter_scope->head;
  }
  while( true ) {
    if (pcVar2 == (c1_sym_link *)0x0) {
      return;
    }
    if ((pcVar2->type).type != (c1_type *)0x0) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,(c1_symbol *)&pcVar2[-1].position);
    }
    if (pcVar2 == (c1_sym_link *)0x0) break;
    pcVar2 = pcVar2->next;
  }
  return;
}

