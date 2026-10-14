void __fastcall alias_expand_unknown_pointees(uint32_t nrefs)

{
  uint8_t uVar1;
  c2_symbol_cell *pcVar2;
  int row_off;
  c2_symbol *unknown_sym;
  c2_alias_ref *refs;
  int local_8;
  c2_symbol_cell *cell;
  c2_symbol_cell *pointees;
  c2_symbol_cell *unknown_member;
  
  local_8 = nrefs - 1;
  if (local_8 == 0) {
    return;
  }
  row_off = local_8 * 0x14;
  unknown_sym = g_alias_special_symbol;
  refs = g_alias_ref_table;
LAB_1078a6bb:
  pointees = *(c2_symbol_cell **)((int)&refs->pointees + row_off);
  for (cell = pointees; cell != (c2_symbol_cell *)0x0; cell = cell->next) {
    uVar1 = cell->sym->cls;
    if ((uVar1 == '\a') || (uVar1 == '\b')) {
      if (cell != (c2_symbol_cell *)0x0) goto joined_r0x1078a6f9;
      break;
    }
  }
  goto LAB_1078a6db;
joined_r0x1078a6f9:
  if (pointees == (c2_symbol_cell *)0x0) goto LAB_1078a706;
  if (pointees->sym == unknown_sym) {
    if (pointees != (c2_symbol_cell *)0x0) goto LAB_1078a6db;
    goto LAB_1078a706;
  }
  pointees = pointees->next;
  goto joined_r0x1078a6f9;
LAB_1078a706:
  unknown_member = (unknown_sym->u30).members;
  while (unknown_member != (c2_symbol_cell *)0x0) {
    pcVar2 = symbol_list_add_unique
                       (*(c2_symbol_cell **)((int)&refs->pointees + row_off),unknown_member->sym,4);
    unknown_member = unknown_member->next;
    *(c2_symbol_cell **)((int)&refs->pointees + row_off) = pcVar2;
    unknown_sym = g_alias_special_symbol;
    refs = g_alias_ref_table;
  }
LAB_1078a6db:
  row_off = row_off + -0x14;
  local_8 = local_8 + -1;
  if (local_8 == 0) {
    return;
  }
  goto LAB_1078a6bb;
}

