void __cdecl func_emit_function_symbol(void)

{
  int iVar1;
  int *piVar2;
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
  (*g_il_emitter->vtbl->set_owner)(g_current_function);
  g_macro_text_pending = iVar1;
  if (g_function_parameter_scope == (c1_scope_symbol_list *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = g_function_parameter_scope->first;
  }
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return;
    }
    if (piVar2[3] != 0) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,(c1_symbol *)(piVar2 + -2));
    }
    if (piVar2 == (int *)0x0) break;
    piVar2 = (int *)piVar2[1];
  }
  return;
}

