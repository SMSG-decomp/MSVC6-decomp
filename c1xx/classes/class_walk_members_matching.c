void __cdecl class_walk_members_matching(c1_symbol *cls,void *name)

{
  fe_name **ppfVar1;
  byte bVar2;
  c1_symbol *sym;
  int iVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  
  sym = class_find_member_function(cls,name);
  if ((sym != (c1_symbol *)0x0) && (ppfVar1 = &sym->name, ppfVar1 != (fe_name **)0x0)) {
    iVar3 = sym_is_data_or_function_2(sym);
    pcVar6 = (c1_symbol *)ppfVar1;
    if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
      pcVar6 = (c1_symbol *)sym->type;
    }
    while ((pcVar5 = pcVar6, ppfVar1 != (fe_name **)0x0 && (pcVar5 != (c1_symbol *)0x0))) {
      iVar3 = sym_is_data_or_function_2(sym);
      if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar6 = *(c1_symbol **)&pcVar5->flags4;
      }
      else {
        pcVar6 = (c1_symbol *)0x0;
      }
      pcVar7 = (c1_symbol *)((int)&pcVar5[-1].tail + 4);
      bVar2 = *(byte *)((int)&pcVar5[-1].tail + 4) & 0x1f;
      pcVar4 = pcVar7;
      if (bVar2 == 0x1a) {
        pcVar4 = *(c1_symbol **)pcVar5->next;
      }
      if ((pcVar4->flags21 & 2) != 0) {
        pcVar4 = pcVar7;
        if (bVar2 == 0x1a) {
          pcVar4 = *(c1_symbol **)pcVar5->next;
        }
        special_member_need_definition(pcVar4);
        if ((cls->flags22 & 4) != 0) {
          if ((pcVar7->kind & 0x1f) == 0x1a) {
            pcVar7 = *(c1_symbol **)pcVar5->next;
          }
          pcVar7->flags21 = pcVar7->flags21 | 0x80;
        }
      }
    }
  }
  return;
}

