void __cdecl sym_set_nesting_depth(c1_symbol *sym)

{
  c1_symbol *unaff_retaddr;
  
  if ((sym->flags1 & 1) == 0) {
    if (((sym->key_ref & 3) == 0) ||
       (g_seh_finally_depth + g_seh_except_depth + g_seh_try_depth <
        (int)(uint)(sym->x28).bytes.depth)) {
      (sym->x28).bytes.depth =
           (char)g_seh_finally_depth + (char)g_seh_except_depth + (char)g_seh_try_depth;
    }
  }
  else if ((sym->flags4 & 2) != 0) {
    stmt_report_jump_into_try(unaff_retaddr);
    return;
  }
  if ((sym->flags1 & 1) != 0) {
    sym->flags4 = sym->flags4 | 4;
  }
  return;
}

