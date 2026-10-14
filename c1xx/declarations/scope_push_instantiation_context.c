void __fastcall scope_push_instantiation_context(c1_parse_state *inst)

{
  c1xx_scope *pcVar1;
  c1_scope_stack *pcVar2;
  c1_u8 *rec;
  c1_decl_state *pcVar3;
  
  rec = g_arenas[8].cur;
  pcVar2 = g_current_scope;
  if (g_current_scope->current != g_current_scope->global_scope) {
    g_arenas[8].cur = g_arenas[8].cur + 0x1c;
    if (g_arenas[8].end < g_arenas[8].cur) {
      arena_grow(g_arenas + 8);
    }
    if (rec == (c1_u8 *)0x0) {
      pcVar3 = (c1_decl_state *)0x0;
    }
    else {
      pcVar3 = decl_state_snapshot((c1_decl_state *)rec,pcVar2,pcVar2->saved,'\x01');
    }
    pcVar2->saved = pcVar3;
    inst->decl_state = pcVar3;
    pcVar2 = g_current_scope;
    pcVar1 = g_current_scope->global_scope;
    g_current_scope->depth = '\0';
    pcVar2->qual_class = (c1_symbol *)0x0;
    pcVar2->qualified = '\0';
    pcVar2->reported = '\0';
    pcVar2->keep_aliases = '\0';
    pcVar2->current = pcVar1;
    pcVar2->access_op = '\x01';
    inst->scope_restore_kind = 2;
    return;
  }
  inst->scope_restore_kind = 1;
  return;
}

