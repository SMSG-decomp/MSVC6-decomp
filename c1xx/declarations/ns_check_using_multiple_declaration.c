void __cdecl ns_check_using_multiple_declaration(c1_symbol *sym,c1_symbol *qualified)

{
  fe_name **ppfVar1;
  bool bVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  c1_symbol *pcVar8;
  c1_symbol *pcVar9;
  
  pcVar6 = sym;
  ppfVar1 = &sym->name;
  pcVar5 = class_current_member_lookup(sym->name);
  if (pcVar5 == (c1_symbol *)0x0) {
    bVar4 = pcVar6->kind & 0x1f;
    if ((bVar4 != 0x11) && (bVar4 != 8)) {
      pcVar6 = symtable_ice_2(*ppfVar1,pcVar6,qualified);
      class_append_member(pcVar6);
      return;
    }
    sym = (c1_symbol *)0x0;
    bVar2 = true;
    pcVar5 = (c1_symbol *)0x0;
    if (((ppfVar1 != (fe_name **)0x0) &&
        (iVar7 = sym_is_data_or_function_2(pcVar6), pcVar5 = (c1_symbol *)ppfVar1,
        (char)iVar7 == '\0')) && ((pcVar6->kind & 0x1f) != 0x1a)) {
      pcVar5 = (c1_symbol *)pcVar6->type;
    }
    while ((ppfVar1 != (fe_name **)0x0 && (pcVar5 != (c1_symbol *)0x0))) {
      iVar7 = sym_is_data_or_function_2(pcVar6);
      if (((char)iVar7 == '\0') && ((pcVar6->kind & 0x1f) != 0x1a)) {
        pcVar9 = *(c1_symbol **)&pcVar5->flags4;
      }
      else {
        pcVar9 = (c1_symbol *)0x0;
      }
      if (bVar2) {
        pcVar8 = (c1_symbol *)((int)&pcVar5[-1].tail + 4);
        bVar2 = false;
        pcVar3 = pcVar8;
        if ((*(byte *)((int)&pcVar5[-1].tail + 4) & 0x1f) == 0x1a) {
          pcVar8 = *(c1_symbol **)pcVar5->next;
          pcVar3 = *(c1_symbol **)pcVar5->next;
        }
        sym = symtable_ice_2(pcVar8->name,pcVar3,qualified);
        class_append_member(sym);
        pcVar5 = pcVar9;
      }
      else {
        pcVar8 = (c1_symbol *)((int)&pcVar5[-1].tail + 4);
        pcVar3 = pcVar8;
        if ((*(byte *)((int)&pcVar5[-1].tail + 4) & 0x1f) == 0x1a) {
          pcVar8 = *(c1_symbol **)pcVar5->next;
          pcVar3 = *(c1_symbol **)pcVar5->next;
        }
        pcVar5 = symtable_ice_2(pcVar8->name,pcVar3,qualified);
        ns_using_declare_target(&sym,pcVar5);
        pcVar5 = pcVar9;
      }
    }
  }
  else {
    bVar4 = pcVar5->kind & 0x1f;
    if ((bVar4 != 0x11) && (bVar4 != 8)) {
      pcVar5 = *(c1_symbol **)(**(int **)qualified->type + 8);
      if ((pcVar5->kind & 0x1f) != 4) {
        pcVar5 = g_scope_vector->entries[(short)pcVar5->key_ref];
      }
      diag_error(0x36b,pcVar5,pcVar6);
    }
  }
  return;
}

