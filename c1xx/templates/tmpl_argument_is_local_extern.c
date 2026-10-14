int __cdecl tmpl_argument_is_local_extern(c1_symbol *sym)

{
  if ((((sym->flags3 & 8) != 0) && ((sym->kind & 0x1f) != 4)) && ((sym->flags3 & 1) == 0)) {
    return 1;
  }
  return 0;
}

