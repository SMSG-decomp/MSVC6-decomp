uint __cdecl ovl_set_has_single_function(char kind,c1_symbol *sym,char exclude_templates)

{
  fe_name **ppfVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  c1_lookup_entry *using_cell;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  uint uStack00000014;
  
  if (kind == '\x06') {
    return 1;
  }
  uVar4 = 0;
  uStack00000014 = 0;
  if ((kind == '\x10') || (kind == '\x11')) {
    ppfVar1 = &sym->name;
    pcVar5 = (c1_symbol *)0x0;
    if ((ppfVar1 != (fe_name **)0x0) &&
       ((iVar3 = sym_is_data_or_function_2(sym), pcVar5 = (c1_symbol *)ppfVar1, (char)iVar3 == '\0'
        && ((sym->kind & 0x1f) != 0x1a)))) {
      pcVar5 = (c1_symbol *)sym->type;
    }
    while ((ppfVar1 != (fe_name **)0x0 && (pcVar5 != (c1_symbol *)0x0))) {
      iVar3 = sym_is_data_or_function_2(sym);
      if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar6 = *(c1_symbol **)&pcVar5->flags4;
      }
      else {
        pcVar6 = (c1_symbol *)0x0;
      }
      uVar2 = ovl_name_function_count((c1_symbol *)((int)&pcVar5[-1].tail + 4),exclude_templates);
      uVar4 = uStack00000014;
      pcVar5 = pcVar6;
      if ((uVar2 == 1) && (uVar4 = uStack00000014 + 1, uStack00000014 = uVar4, 1 < uVar4)) {
        return 2;
      }
    }
  }
  else {
    if (kind != '\x1b') {
      return 0;
    }
    using_cell = *(c1_lookup_entry **)sym->type;
    do {
      uVar2 = ovl_name_function_count(using_cell->sym,exclude_templates);
      if (uVar2 == 1) {
        uVar4 = uVar4 + 1;
        if (1 < uVar4) {
          return 2;
        }
      }
      else if (uVar2 == 2) {
        return 2;
      }
      using_cell = using_cell->next;
    } while (using_cell != (c1_lookup_entry *)0x0);
  }
  return (uint)(uVar4 == 1);
}

