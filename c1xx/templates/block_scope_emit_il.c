void __fastcall block_scope_emit_il(c1xx_block_scope *scope)

{
  c1_sym_link *symref;
  
  if (scope->symbols == (c1_sym_list *)0x0) {
    symref = (c1_sym_link *)0x0;
  }
  else {
    symref = scope->symbols->tail;
  }
  if (g_error_count == 0) {
    g_il_block_level = scope->kind;
    il_emit_symbol(0xd,(c1_symbol *)0x0);
    for (; symref != (c1_sym_link *)0x0; symref = (c1_sym_link *)symref[1].type.entries) {
      il_emit_global_symbol((int *)symref);
    }
  }
  return;
}

