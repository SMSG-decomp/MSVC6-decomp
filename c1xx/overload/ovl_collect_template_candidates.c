void __thiscall ovl_collect_template_candidates(void *result,c1_symbol *sym)

{
  fe_name **ppfVar1;
  c1_symbol **ppcVar2;
  byte bVar3;
  int iVar4;
  c1_tmpl_deduction *pcVar5;
  c1_symbol_vector *pcVar6;
  short *psVar7;
  c1_symbol *sym_00;
  c1_symbol *pcVar8;
  c1_symbol *pcVar9;
  void **member_cell;
  
  if ((sym->kind & 0x1f) == 0x1a) {
    if (*(char *)((int)&sym->type->extra + 2) != '\0') {
      return;
    }
    sym = *(c1_symbol **)sym->type;
  }
  bVar3 = sym->kind & 0x1f;
  if ((bVar3 != 7) && (bVar3 != 6)) {
    if ((bVar3 == 0x1a) &&
       (iVar4 = sym_is_kind_6_7_through_alias(*(c1_symbol **)sym->type), (char)iVar4 != '\0')) {
      ovl_collect_template_candidates_one(result,sym);
      return;
    }
    bVar3 = sym->kind & 0x1f;
    if (bVar3 != 8) {
      if ((bVar3 == 0x1a) &&
         (iVar4 = sym_is_member_function_via_alias(*(c1_symbol **)sym->type), (char)iVar4 != '\0'))
      {
        ovl_collect_template_candidates_one(result,sym);
        return;
      }
      bVar3 = sym->kind & 0x1f;
      if ((bVar3 != 0x10) && (bVar3 != 0x11)) {
        member_cell = *(void ***)sym->type;
        do {
          ovl_collect_template_candidates(result,*member_cell);
          member_cell = member_cell[2];
        } while (member_cell != (void **)0x0);
        return;
      }
      ppfVar1 = &sym->name;
      if (ppfVar1 == (fe_name **)0x0) {
        return;
      }
      iVar4 = sym_is_data_or_function_2(sym);
      pcVar8 = (c1_symbol *)ppfVar1;
      if (((char)iVar4 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar8 = (c1_symbol *)sym->type;
      }
LAB_10426d32:
      if (ppfVar1 == (fe_name **)0x0) {
        return;
      }
      if (pcVar8 == (c1_symbol *)0x0) {
        return;
      }
      iVar4 = sym_is_data_or_function_2(sym);
      if (((char)iVar4 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar9 = *(c1_symbol **)&pcVar8->flags4;
      }
      else {
        pcVar9 = (c1_symbol *)0x0;
      }
      sym_00 = (c1_symbol *)((int)&pcVar8[-1].tail + 4);
      if ((*(byte *)((int)&pcVar8[-1].tail + 4) & 0x1f) == 0x1a) goto LAB_104a7019;
      goto LAB_10426d6e;
    }
  }
  if ((sym->kind & 0x1f) == 0x1a) {
    bVar3 = *(byte *)(*(int *)sym->type + 0x35);
  }
  else {
    bVar3 = *(byte *)((int)&sym->tail + 9);
  }
  if (((bVar3 >> 5 & 1) != 0) &&
     (pcVar5 = tmpl_deduce_from_call(result,sym), pcVar5 != (c1_tmpl_deduction *)0x0)) {
    if (*(int *)((int)result + 4) == 0) {
      pcVar6 = symtab_record_new(1);
      *(c1_symbol_vector **)((int)result + 4) = pcVar6;
    }
    psVar7 = vector_find_or_add(*(short **)((int)result + 4),(int)pcVar5);
    *(short **)((int)result + 4) = psVar7;
  }
  return;
LAB_104a7019:
  ppcVar2 = &pcVar8->next;
  pcVar8 = pcVar9;
  if (*(char *)((int)&(*ppcVar2)->name + 2) == '\0') {
    sym_00 = *(c1_symbol **)*ppcVar2;
LAB_10426d6e:
    if ((sym_00->kind & 0x1f) == 0x1a) {
      bVar3 = *(byte *)(*(int *)sym_00->type + 0x35);
    }
    else {
      bVar3 = *(byte *)((int)&sym_00->tail + 9);
    }
    pcVar8 = pcVar9;
    if (((bVar3 >> 5 & 1) != 0) &&
       (pcVar5 = tmpl_deduce_from_call(result,sym_00), pcVar5 != (c1_tmpl_deduction *)0x0)) {
      if (*(int *)((int)result + 4) == 0) {
        pcVar6 = symtab_record_new(1);
        *(c1_symbol_vector **)((int)result + 4) = pcVar6;
      }
      psVar7 = vector_find_or_add(*(short **)((int)result + 4),(int)pcVar5);
      *(short **)((int)result + 4) = psVar7;
    }
  }
  goto LAB_10426d32;
}

