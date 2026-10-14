void sym_ensure_global_helper_function(void)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 *pcVar5;
  uint uVar6;
  char local_4;
  
  cVar4 = g_block_depth;
  cVar3 = g_il_block_level;
  if (g_global_helper_key != 0) {
    return;
  }
  g_il_block_level = '\0';
  g_block_depth = '\0';
  if (g_line_var_symbol == (c1_symbol *)0x0) {
    g_line_var_symbol = sym_new_in_scope_arena_2(g_name_LINE_Var);
    g_line_var_symbol->kind = g_line_var_symbol->kind & 0xea | 10;
    g_line_var_symbol->storage = g_line_var_symbol->storage & 0xf8 ^ 3;
    g_line_var_symbol->type = g_type_short;
    g_line_var_symbol->flags3 = g_line_var_symbol->flags3 | 4;
    g_line_var_symbol->flags1 = g_line_var_symbol->flags1 | 1;
    pcVar5 = &g_line_var_symbol->storage;
    bVar1 = *pcVar5;
    pcVar2 = g_line_var_symbol;
    pcVar2->storage = '\0';
    pcVar2->flags21 = '\0';
    pcVar2->flags22 = '\0';
    pcVar2->flags23 = '\0';
    *pcVar5 = (*pcVar5 ^ bVar1 & 7) & 7 ^ *pcVar5;
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,g_line_var_symbol);
LAB_1064dd14:
    if ((g_opt_ZI != '\0') && (g_c9il_mode != '\0')) {
      if ((((g_current_function->flags21 & 1) != 0) && ((g_current_function->storage & 7) == 3)) ||
         (local_4 = '\0', (g_current_function->storage & 7) == 3)) {
        local_4 = '\x01';
      }
      sym_global_helper_set_decorated_name(local_4);
      g_line_var_symbol->storage = g_line_var_symbol->storage & 0xf8 ^ 2;
      g_line_var_symbol->storage = g_line_var_symbol->storage | 0x40;
      goto LAB_1064dd7c;
    }
  }
  else if (g_opt_ZI != '\0') {
    if (g_c9il_mode != '\0') {
      g_line_var_symbol->flags3 = g_line_var_symbol->flags3 & 0xfb;
      g_line_var_symbol->flags4 = g_line_var_symbol->flags4 & 0xbf;
      g_line_var_symbol->storage = g_line_var_symbol->storage & 0xbf;
      g_line_var_symbol->storage = g_line_var_symbol->storage & 0xf8 ^ 3;
    }
    goto LAB_1064dd14;
  }
  sym_global_helper_set_decorated_name_2();
LAB_1064dd7c:
  g_line_var_symbol->key_ref = g_line_var_symbol->key_ref & 7;
  if ((g_opt_ZI == '\0') || (g_c9il_mode == '\0')) {
    if ((g_c9il_mode == '\0') && ((g_line_var_symbol->key_ref & 0xfffffff8) == 0)) {
      il_symbol_key_assign(g_line_var_symbol);
    }
  }
  else {
    il_symbol_key_assign(g_line_var_symbol);
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar6 = g_line_var_symbol->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    g_line_var_symbol->entity = uVar6 & 0xffffff ^ g_line_var_symbol->entity;
  }
  g_global_helper_key = g_line_var_symbol->key_ref >> 3;
  g_line_var_symbol->name = g_name_LINE_Var;
  g_line_var_symbol->flags1 = g_line_var_symbol->flags1 | 0x40;
  g_il_block_level = cVar3;
  g_block_depth = cVar4;
  return;
}

