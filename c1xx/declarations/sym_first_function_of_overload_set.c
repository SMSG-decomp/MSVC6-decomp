c1_symbol * __cdecl sym_first_function_of_overload_set(c1_symbol *sym,char flag)

{
  byte bVar1;
  c1_symbol *pcVar2;
  
  if ((sym->kind & 0x1f) == 0x1a) {
    if (*(char *)((int)&sym->type->extra + 2) != '\0') {
      return (c1_symbol *)0x0;
    }
    sym = *(c1_symbol **)sym->type;
  }
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 != 8) && (bVar1 != 7)) {
    pcVar2 = sym_resolve_single_function(bVar1,sym,flag);
    return pcVar2;
  }
  bVar1 = *(byte *)((int)&sym->tail + 9);
  if (((bVar1 & 0x20) != 0) && (flag != '\0')) {
    return (c1_symbol *)0x0;
  }
  return (c1_symbol *)(~-(uint)((bVar1 & 0x40) != 0) & (uint)sym);
}

