void __cdecl pragma_alloc_text_name(fe_name *name)

{
  fe_name **ppfVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar5;
  int iVar6;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  c1_symbol *pcVar9;
  c1_symbol *pcVar10;
  c1_symbol *pcVar11;
  c1_symbol *sym;
  
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if ((result == (c1_lookup_result *)0x0) ||
     (pcVar5 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar5 == (c1_lookup_entry *)0x0)) {
    pcVar7 = (c1_symbol *)0x0;
  }
  else {
    pcVar7 = pcVar5->sym;
  }
  if (pcVar7 == (c1_symbol *)0x0) {
    diag_error(0x9d,name);
    return;
  }
  sym = pcVar7;
  if ((g_compile_flags_c4 & 0x10000) == 0) goto LAB_1047af25;
  bVar4 = pcVar7->kind & 0x1f;
  bVar3 = false;
  bVar2 = false;
  if (((bVar4 != 0x10) && (bVar4 != 7)) && (bVar4 != 6)) {
    diag_error(0x3f,pcVar7);
    return;
  }
  ppfVar1 = &pcVar7->name;
  if (ppfVar1 == (fe_name **)0x0) {
LAB_1047af01:
    if (!bVar2) {
      diag_error(0x80,sym);
      return;
    }
    if (bVar3) goto LAB_1047aecb;
  }
  else {
    iVar6 = sym_is_data_or_function_2(pcVar7);
    pcVar9 = (c1_symbol *)ppfVar1;
    if (((char)iVar6 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
      pcVar9 = (c1_symbol *)pcVar7->type;
    }
    do {
      while( true ) {
        if ((ppfVar1 == (fe_name **)0x0) || (pcVar9 == (c1_symbol *)0x0)) goto LAB_1047af01;
        iVar6 = sym_is_data_or_function_2(pcVar7);
        if (((char)iVar6 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
          pcVar10 = *(c1_symbol **)&pcVar9->flags4;
        }
        else {
          pcVar10 = (c1_symbol *)0x0;
        }
        pcVar11 = (c1_symbol *)((int)&pcVar9[-1].tail + 4);
        bVar4 = *(byte *)((int)&pcVar9[-1].tail + 4) & 0x1f;
        pcVar8 = pcVar11;
        if (bVar4 == 0x1a) {
          pcVar8 = *(c1_symbol **)pcVar9->next;
        }
        if ((pcVar8->flags1 & 2) == 0) break;
        bVar2 = true;
        if (bVar4 == 0x1a) {
          pcVar11 = *(c1_symbol **)pcVar9->next;
        }
        pcVar9 = pcVar10;
        sym = pcVar11;
        if (bVar3) goto LAB_1047aecb;
      }
      bVar3 = true;
      pcVar9 = pcVar10;
    } while (!bVar2);
LAB_1047aecb:
    diag_warning(1,0x7a,name);
  }
  if ((sym->flags2 & 4) != 0) {
    diag_error(200,sym);
  }
LAB_1047af25:
  if ((sym->flags23 & 1) != 0) {
    pcVar7 = sym_segment_record(sym);
    if (pcVar7 == g_alloc_text_segment) {
      return;
    }
    diag_error(0xc1,sym);
    return;
  }
  if ((g_compile_flags_c4 & 0x10000) == 0) {
    if ((sym->kind & 0x1f) != 10) {
      sym->flags3 = sym->flags3 | 4;
      diag_error(0x9e,sym);
      return;
    }
    if ((sym->storage & 7) != 1) {
      sym->flags3 = sym->flags3 | 4;
      diag_error(0xb2,sym);
      return;
    }
  }
  sym_set_segment_checked(sym,g_alloc_text_segment);
  return;
}

