c1_symbol * __cdecl sym_resolve_single_function(char kind,c1_symbol *sym,char flag)

{
  fe_name **ppfVar1;
  int iVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  void **target_cell;
  c1_symbol *pcVar5;
  
  if (kind == '\x06') {
    return sym;
  }
  if (((kind == '\x10') || (kind == '\x11')) && (ppfVar1 = &sym->name, ppfVar1 != (fe_name **)0x0))
  {
    iVar2 = sym_is_data_or_function_2(sym);
    pcVar4 = (c1_symbol *)ppfVar1;
    if (((char)iVar2 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
      pcVar4 = (c1_symbol *)sym->type;
    }
    while ((ppfVar1 != (fe_name **)0x0 && (pcVar4 != (c1_symbol *)0x0))) {
      iVar2 = sym_is_data_or_function_2(sym);
      if (((char)iVar2 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar5 = *(c1_symbol **)&pcVar4->flags4;
      }
      else {
        pcVar5 = (c1_symbol *)0x0;
      }
      pcVar3 = sym_first_function_of_overload_set((c1_symbol *)((int)&pcVar4[-1].tail + 4),flag);
      pcVar4 = pcVar5;
      if (pcVar3 != (c1_symbol *)0x0) {
        return pcVar3;
      }
    }
  }
  if ((sym->kind & 0x1f) == 0x1b) {
    target_cell = *(void ***)sym->type;
    pcVar4 = sym_first_function_of_overload_set(*target_cell,flag);
    if (pcVar4 != (c1_symbol *)0x0) {
      return pcVar4;
    }
    while (target_cell = target_cell[2], target_cell != (void **)0x0) {
      pcVar4 = sym_first_function_of_overload_set(*target_cell,flag);
      if (pcVar4 != (c1_symbol *)0x0) {
        return pcVar4;
      }
    }
  }
  return (c1_symbol *)0x0;
}

