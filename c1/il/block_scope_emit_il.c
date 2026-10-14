void __fastcall block_scope_emit_il(c1_scope_object *block_scope)

{
  int *sym_link;
  
  if ((block_scope->entries).list == (c1_scope_symbol_list *)0x0) {
    sym_link = (int *)0x0;
  }
  else {
    sym_link = ((block_scope->entries).list)->last;
  }
  if (g_error_count == 0) {
    g_il_block_level = block_scope->level;
    il_emit_symbol(0xd,(c1_symbol *)0x0);
    for (; sym_link != (int *)0x0; sym_link = (int *)sym_link[7]) {
      il_emit_global_symbol(sym_link);
    }
  }
  return;
}

