void __fastcall scope_for_each(int function_scope,c2_fn_fn *fn)

{
  c2_fe_symbol *sym;
  c2_scope_table *scope;
  
  scope = &g_global_scope;
  if (function_scope != 0) {
    scope = g_cur_scope;
  }
  if (scope != (c2_scope_table *)0x0) {
    for (sym = scope_iter_next(scope,(c2_fe_symbol *)0x0); sym != (c2_fe_symbol *)0x0;
        sym = scope_iter_next(scope,sym)) {
      (*fn)(sym);
    }
  }
  return;
}

