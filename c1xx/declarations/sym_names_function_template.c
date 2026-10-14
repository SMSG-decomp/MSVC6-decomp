char __cdecl sym_names_function_template(c1_symbol *sym)

{
  fe_name **ppfVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  uint *cell;
  
  bVar2 = sym->kind & 0x1f;
  if ((bVar2 != 7) && (bVar2 != 8)) {
    if ((sym->flags4 & 0x40) == 0) {
      if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
        ppfVar1 = &sym->name;
        if (ppfVar1 != (fe_name **)0x0) {
          iVar4 = sym_is_data_or_function_2(sym);
          pcVar5 = (c1_symbol *)ppfVar1;
          if (((char)iVar4 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
            pcVar5 = (c1_symbol *)sym->type;
          }
          while ((ppfVar1 != (fe_name **)0x0 && (pcVar5 != (c1_symbol *)0x0))) {
            iVar4 = sym_is_data_or_function_2(sym);
            if (((char)iVar4 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
              pcVar6 = *(c1_symbol **)&pcVar5->flags4;
            }
            else {
              pcVar6 = (c1_symbol *)0x0;
            }
            cVar3 = sym_names_function_template((c1_symbol *)((int)&pcVar5[-1].tail + 4));
            pcVar5 = pcVar6;
            if (cVar3 != '\0') {
              return '\x01';
            }
          }
        }
      }
      else if (bVar2 == 0x1b) {
        cell = *(uint **)sym->type;
        cVar3 = sym_names_function_template((c1_symbol *)*cell);
        while( true ) {
          if (cVar3 != '\0') {
            return '\x01';
          }
          cell = (uint *)cell[2];
          if (cell == (uint *)0x0) break;
          cVar3 = sym_names_function_template((c1_symbol *)*cell);
        }
      }
    }
    else if (*(char *)((int)&sym->type->extra + 2) == '\0') {
      sym = *(c1_symbol **)sym->type;
      bVar2 = sym->kind & 0x1f;
      if ((bVar2 == 7) || (bVar2 == 8)) goto LAB_104b66fb;
    }
    return '\0';
  }
LAB_104b66fb:
  return (char)((*(byte *)((int)&sym->tail + 9) & 0x20) >> 5);
}

