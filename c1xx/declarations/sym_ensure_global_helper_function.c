void __cdecl sym_ensure_global_helper_function(void)

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
  if (PTR_104d1b38 == (c1_symbol *)0x0) {
    PTR_104d1b38 = sym_new_kind1_placeholder(g_name_line_var);
    PTR_104d1b38->kind = PTR_104d1b38->kind & 0xea | 10;
    PTR_104d1b38->storage = PTR_104d1b38->storage & 0xf8 ^ 3;
    PTR_104d1b38->type = g_type_short;
    PTR_104d1b38->flags4 = PTR_104d1b38->flags4 | 4;
    PTR_104d1b38->flags2 = PTR_104d1b38->flags2 | 4;
    pcVar5 = &PTR_104d1b38->storage;
    bVar1 = *pcVar5;
    pcVar2 = PTR_104d1b38;
    pcVar2->storage = '\0';
    pcVar2->flags21 = '\0';
    pcVar2->flags22 = '\0';
    pcVar2->flags23 = '\0';
    *pcVar5 = (*pcVar5 ^ bVar1 & 7) & 7 ^ *pcVar5;
    (*g_current_scope->global_scope->vtbl->insert)(PTR_104d1b38);
LAB_1049a854:
    if ((g_opt_ZI != '\0') && (g_c9il_mode != '\0')) {
      if (((((g_current_function->flags21 & 1) != 0) && ((g_current_function->storage & 7) == 3)) &&
          ((g_current_function->flags1 & 4) == 0)) ||
         (local_4 = '\0', (g_current_function->storage & 7) == 3)) {
        local_4 = '\x01';
      }
      global_helper_name_decorated(local_4);
      PTR_104d1b38->storage = PTR_104d1b38->storage & 0xf8 ^ 2;
      PTR_104d1b38->storage = PTR_104d1b38->storage | 0x40;
      goto LAB_1049a8c3;
    }
  }
  else if (g_opt_ZI != '\0') {
    if (g_c9il_mode != '\0') {
      PTR_104d1b38->flags4 = PTR_104d1b38->flags4 & 0xfb;
      PTR_104d1b38->flags5 = PTR_104d1b38->flags5 & 0xbf;
      PTR_104d1b38->storage = PTR_104d1b38->storage & 0xbf;
      PTR_104d1b38->storage = PTR_104d1b38->storage & 0xf8 ^ 3;
    }
    goto LAB_1049a854;
  }
  global_helper_name_plain();
LAB_1049a8c3:
  PTR_104d1b38->key_ref = PTR_104d1b38->key_ref & 7;
  if ((g_opt_ZI == '\0') || (g_c9il_mode == '\0')) {
    if ((g_c9il_mode == '\0') && ((PTR_104d1b38->key_ref & 0xfffffff8) == 0)) {
      il_symbol_key_assign(PTR_104d1b38);
    }
  }
  else {
    il_symbol_key_assign(PTR_104d1b38);
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar6 = PTR_104d1b38->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    PTR_104d1b38->entity = uVar6 & 0xffffff ^ PTR_104d1b38->entity;
  }
  g_global_helper_key = PTR_104d1b38->key_ref >> 3;
  PTR_104d1b38->name = g_name_line_var;
  PTR_104d1b38->flags3 = PTR_104d1b38->flags3 | 1;
  g_il_block_level = cVar3;
  g_block_depth = cVar4;
  return;
}

