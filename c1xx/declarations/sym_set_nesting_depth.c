void __cdecl sym_set_nesting_depth(c1_symbol *sym)

{
  if ((sym->flags2 & 4) == 0) {
    if (((sym->key_ref & 3) == 0) ||
       (g_seh_finally_depth + g_seh_except_depth + g_seh_try_depth <
        (int)(uint)(sym->x28).bytes.depth)) {
      (sym->x28).bytes.depth =
           (char)g_seh_finally_depth + (char)g_seh_except_depth + (char)g_seh_try_depth;
    }
  }
  else if ((sym->flags5 & 2) != 0) {
    stmt_report_jump_into_try(sym);
    return;
  }
  if ((sym->flags2 & 4) != 0) {
    sym->flags5 = sym->flags5 | 4;
  }
  return;
}

