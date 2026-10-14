void __thiscall ovl_add_deduced_template_candidates(void *this,c1_symbol *sym)

{
  fe_name **ppfVar1;
  byte bVar2;
  int iVar3;
  c1_tmpl_deduction *pcVar4;
  c1_symbol_vector *pcVar5;
  short *psVar6;
  c1_symbol *sym_00;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  uint *cell;
  
  if ((sym->kind & 0x1f) == 0x1a) {
    if (*(char *)((int)&sym->type->extra + 2) != '\0') {
      return;
    }
    sym = *(c1_symbol **)sym->type;
  }
  bVar2 = sym->kind & 0x1f;
  if (((((bVar2 == 7) || (bVar2 == 6)) ||
       ((bVar2 == 0x1a &&
        (iVar3 = sym_is_kind_6_7_through_alias(*(c1_symbol **)sym->type), (char)iVar3 != '\0')))) ||
      (bVar2 = sym->kind & 0x1f, bVar2 == 8)) ||
     ((bVar2 == 0x1a &&
      (iVar3 = sym_is_member_function_via_alias(*(c1_symbol **)sym->type), (char)iVar3 != '\0')))) {
    if ((sym->kind & 0x1f) == 0x1a) {
      bVar2 = *(byte *)(*(int *)sym->type + 0x35);
    }
    else {
      bVar2 = *(byte *)((int)&sym->tail + 9);
    }
    if (((bVar2 >> 5 & 1) != 0) &&
       (pcVar4 = tmpl_deduce_from_operands(this,sym), pcVar4 != (c1_tmpl_deduction *)0x0)) {
      if (*(int *)((int)this + 4) == 0) {
        pcVar5 = symtab_record_new(1);
        *(c1_symbol_vector **)((int)this + 4) = pcVar5;
      }
      psVar6 = vector_find_or_add(*(short **)((int)this + 4),(int)pcVar4);
      *(short **)((int)this + 4) = psVar6;
    }
  }
  else {
    if ((sym->kind & 0x1f) == 0x1b) {
      cell = *(uint **)sym->type;
      do {
        ovl_add_deduced_template_candidates(this,(c1_symbol *)*cell);
        cell = (uint *)cell[2];
      } while (cell != (uint *)0x0);
      return;
    }
    ppfVar1 = &sym->name;
    if (ppfVar1 != (fe_name **)0x0) {
      iVar3 = sym_is_data_or_function_2(sym);
      pcVar7 = (c1_symbol *)ppfVar1;
      if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
        pcVar7 = (c1_symbol *)sym->type;
      }
      while ((ppfVar1 != (fe_name **)0x0 && (pcVar7 != (c1_symbol *)0x0))) {
        iVar3 = sym_is_data_or_function_2(sym);
        if (((char)iVar3 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
          pcVar8 = *(c1_symbol **)&pcVar7->flags4;
        }
        else {
          pcVar8 = (c1_symbol *)0x0;
        }
        sym_00 = (c1_symbol *)((int)&pcVar7[-1].tail + 4);
        if ((*(byte *)((int)&pcVar7[-1].tail + 4) & 0x1f) == 0x1a) {
          if (*(char *)((int)&pcVar7->next->name + 2) != '\0') {
            return;
          }
          sym_00 = *(c1_symbol **)pcVar7->next;
        }
        if ((sym_00->kind & 0x1f) == 0x1a) {
          bVar2 = *(byte *)(*(int *)sym_00->type + 0x35);
        }
        else {
          bVar2 = *(byte *)((int)&sym_00->tail + 9);
        }
        pcVar7 = pcVar8;
        if (((bVar2 >> 5 & 1) != 0) &&
           (pcVar4 = tmpl_deduce_from_operands(this,sym_00), pcVar4 != (c1_tmpl_deduction *)0x0)) {
          if (*(int *)((int)this + 4) == 0) {
            pcVar5 = symtab_record_new(1);
            *(c1_symbol_vector **)((int)this + 4) = pcVar5;
          }
          psVar6 = vector_find_or_add(*(short **)((int)this + 4),(int)pcVar4);
          *(short **)((int)this + 4) = psVar6;
        }
      }
    }
  }
  return;
}

