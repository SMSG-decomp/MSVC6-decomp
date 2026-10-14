void __cdecl
tmpl_deduce_from_function(c1_type *type,c1_symbol *sym,short **specializations,byte resolve_flags)

{
  fe_name **ppfVar1;
  c1_symbol *pcVar2;
  byte bVar3;
  int iVar4;
  c1_symbol *pcVar5;
  c1_symbol_vector *pcVar6;
  short *psVar7;
  c1_symbol *pcVar8;
  uint *cell;
  
  bVar3 = sym->kind & 0x1f;
  if (((((bVar3 == 7) || (bVar3 == 6)) ||
       ((bVar3 == 0x1a &&
        (iVar4 = sym_is_kind_6_7_through_alias(*(c1_symbol **)sym->type), (char)iVar4 != '\0')))) ||
      (bVar3 = sym->kind & 0x1f, bVar3 == 8)) ||
     ((bVar3 == 0x1a &&
      (iVar4 = sym_is_member_function_via_alias(*(c1_symbol **)sym->type), (char)iVar4 != '\0')))) {
    if ((sym->kind & 0x1f) == 0x1a) {
      bVar3 = *(byte *)(*(int *)sym->type + 0x35);
    }
    else {
      bVar3 = *(byte *)((int)&sym->tail + 9);
    }
    if (((bVar3 >> 5 & 1) != 0) &&
       (pcVar8 = tmpl_deduce_from_target_type(type,sym,resolve_flags), pcVar8 != (c1_symbol *)0x0))
    {
      if (*specializations == (short *)0x0) {
        pcVar6 = symtab_record_new(1);
        *specializations = (short *)pcVar6;
      }
      psVar7 = vector_find_or_add(*specializations,(int)pcVar8);
      *specializations = psVar7;
    }
  }
  else {
    bVar3 = sym->kind & 0x1f;
    if ((bVar3 != 0x10) && (bVar3 != 0x11)) {
      cell = *(uint **)sym->type;
      do {
        tmpl_deduce_from_function(type,(c1_symbol *)*cell,specializations,resolve_flags);
        cell = (uint *)cell[2];
      } while (cell != (uint *)0x0);
      return;
    }
    ppfVar1 = &sym->name;
    pcVar8 = (c1_symbol *)0x0;
    if (((ppfVar1 != (fe_name **)0x0) &&
        (iVar4 = sym_is_data_or_function_2(sym), pcVar8 = (c1_symbol *)ppfVar1, (char)iVar4 == '\0')
        ) && ((sym->kind & 0x1f) != 0x1a)) {
      pcVar8 = (c1_symbol *)sym->type;
    }
    while ((ppfVar1 != (fe_name **)0x0 && (pcVar8 != (c1_symbol *)0x0))) {
      iVar4 = sym_is_data_or_function_2(sym);
      if (((char)iVar4 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar5 = *(c1_symbol **)&pcVar8->flags4;
      }
      else {
        pcVar5 = (c1_symbol *)0x0;
      }
      pcVar2 = pcVar8 + -1;
      if ((*(byte *)((int)&pcVar8[-1].tail + 4) & 0x1f) == 0x1a) {
        bVar3 = *(byte *)(*(int *)pcVar8->next + 0x35);
      }
      else {
        bVar3 = *(byte *)((int)&pcVar8->tail + 1);
      }
      pcVar8 = pcVar5;
      if (((bVar3 >> 5 & 1) != 0) &&
         (pcVar5 = tmpl_deduce_from_target_type
                             (type,(c1_symbol *)((int)&pcVar2->tail + 4),resolve_flags),
         pcVar5 != (c1_symbol *)0x0)) {
        if (*specializations == (short *)0x0) {
          pcVar6 = symtab_record_new(1);
          *specializations = (short *)pcVar6;
        }
        psVar7 = vector_find_or_add(*specializations,(int)pcVar5);
        *specializations = psVar7;
      }
    }
  }
  return;
}

