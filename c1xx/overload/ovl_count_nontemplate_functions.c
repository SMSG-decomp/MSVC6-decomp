int __cdecl ovl_count_nontemplate_functions(c1_symbol *sym)

{
  fe_name **ppfVar1;
  byte bVar2;
  int iVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  int iVar6;
  uint *link;
  
  bVar2 = sym->kind & 0x1f;
  if (((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) {
    if ((*(byte *)((int)&sym->tail + 9) & 0xe0) != 0) {
      return 0;
    }
    return 1;
  }
  if (bVar2 != 0x1a) {
    iVar6 = 0;
    if (bVar2 != 0x1b) {
      ppfVar1 = &sym->name;
      if (ppfVar1 != (fe_name **)0x0) {
        iVar3 = sym_is_data_or_function_2(sym);
        pcVar5 = (c1_symbol *)ppfVar1;
        if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
          pcVar5 = (c1_symbol *)sym->type;
        }
        while ((pcVar4 = pcVar5, ppfVar1 != (fe_name **)0x0 && (pcVar4 != (c1_symbol *)0x0))) {
          iVar3 = sym_is_data_or_function_2(sym);
          if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
            pcVar5 = *(c1_symbol **)&pcVar4->flags4;
          }
          else {
            pcVar5 = (c1_symbol *)0x0;
          }
          bVar2 = *(byte *)((int)&pcVar4[-1].tail + 4) & 0x1f;
          if (((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) {
            if ((*(byte *)((int)&pcVar4->tail + 1) & 0xe0) == 0) {
              iVar6 = iVar6 + 1;
            }
          }
          else if (((bVar2 == 0x1a) && (*(char *)((int)&pcVar4->next->name + 2) == '\0')) &&
                  ((*(byte *)(*(int *)pcVar4->next + 0x35) & 0xe0) == 0)) {
            iVar6 = iVar6 + 1;
          }
        }
      }
      return iVar6;
    }
    link = *(uint **)sym->type;
    do {
      iVar3 = ovl_count_nontemplate_functions((c1_symbol *)*link);
      link = (uint *)link[2];
      iVar6 = iVar6 + iVar3;
    } while (link != (uint *)0x0);
    return iVar6;
  }
  if ((*(char *)((int)&sym->type->extra + 2) == '\0') &&
     ((*(byte *)(*(int *)sym->type + 0x35) & 0xe0) == 0)) {
    return 1;
  }
  return 0;
}

