byte * __cdecl ovl_first_function_of_set(c1_symbol *sym)

{
  fe_name **ppfVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  
  ppfVar1 = &sym->name;
  if (ppfVar1 != (fe_name **)0x0) {
    bVar2 = sym->kind & 0x1f;
    pcVar4 = (c1_symbol *)ppfVar1;
    if ((((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) && ((sym->kind & 0x1f) != 0x1a)) {
      pcVar4 = (c1_symbol *)sym->type;
    }
    do {
      while( true ) {
        pcVar3 = pcVar4;
        if (ppfVar1 == (fe_name **)0x0) {
          return &sym->kind;
        }
        if (pcVar3 == (c1_symbol *)0x0) {
          return &sym->kind;
        }
        bVar2 = sym->kind & 0x1f;
        if (((bVar2 == 7) || (bVar2 == 8)) || ((bVar2 == 6 || ((sym->kind & 0x1f) == 0x1a)))) {
          pcVar4 = (c1_symbol *)0x0;
        }
        else {
          pcVar4 = *(c1_symbol **)&pcVar3->flags4;
        }
        if ((*(byte *)((int)&pcVar3[-1].tail + 4) & 0x1f) == 0x1a) break;
        if (((byte)~*(byte *)((int)&pcVar3->tail + 1) >> 6 & 1) != 0) goto LAB_1041bf01;
      }
    } while ((*(char *)((int)&pcVar3->next->name + 2) != '\0') ||
            ((*(byte *)(*(int *)pcVar3->next + 0x35) & 0x40) != 0));
LAB_1041bf01:
    sym = (c1_symbol *)((int)&pcVar3[-1].tail + 4);
    if ((*(byte *)((int)&pcVar3[-1].tail + 4) & 0x1f) == 0x1a) {
      return *(byte **)pcVar3->next;
    }
  }
  return &sym->kind;
}

