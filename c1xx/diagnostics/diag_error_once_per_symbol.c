void __cdecl diag_error_once_per_symbol(short n,c1_symbol *sym)

{
  if ((sym->flags3 & 4) == 0) {
    diag_error(n,sym);
    sym->flags3 = sym->flags3 | 4;
  }
  return;
}

