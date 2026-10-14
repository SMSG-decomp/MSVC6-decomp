void __cdecl decl_error_once_per_symbol(int n,c1_symbol *sym)

{
  if ((sym->flags2 & 1) == 0) {
    diag_error((short)n,sym);
    sym->flags2 = sym->flags2 | 1;
  }
  return;
}

