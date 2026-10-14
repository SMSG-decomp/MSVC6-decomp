void __fastcall sym_mark_ellipsis_parameter(c1_symbol *sym)

{
  sym->flags2 = sym->flags2 | 8;
  return;
}

