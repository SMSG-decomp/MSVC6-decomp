int __cdecl debug_type_record_class_forward(c1_symbol *sym)

{
  c1_symbol *sym_00;
  ushort *puVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  c1_u32 cVar6;
  int iVar7;
  
  puVar1 = g_cv_record_body;
  uVar4 = sym->type->code;
  cVar6 = sym->type->debug_index;
  if (cVar6 != 0) {
    return cVar6;
  }
  if (sym->name == g_name_unnamed) {
    cVar6 = debug_type_record_class_full(sym);
    sym->type->debug_index = cVar6;
    return cVar6;
  }
  free_list_push_124c(sym);
  if (((((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) &&
       ((g_compile_flags_cc & 0x100000) == 0)) &&
      (((g_compile_flags_cc & 0x20) == 0 && ((g_compile_flags_c8 & 0x10000000) == 0)))) &&
     (cVar2 = sym_is_deferrable(sym), cVar2 != '\0')) {
    sym_defer_emission(sym);
  }
  sym->flags2 = sym->flags2 & 0xf7;
  if ((((sym->detail).cls)->layout_flags3b & 2) != 0) {
    for (sym_00 = g_scope_vector->entries[(short)sym->scope_index];
        (sym_00 != (c1_symbol *)0x0 && ((sym_00->kind & 0x1f) == 4));
        sym_00 = g_scope_vector->entries[(short)sym_00->scope_index]) {
      if (sym_00->name != g_name_unnamed) {
        debug_type_record_class_forward(sym_00);
      }
    }
  }
  puVar1[1] = 0;
  if (uVar4 == 0x201) {
    *puVar1 = 0x1004;
  }
  else {
    if (uVar4 != 0x202) {
      if (uVar4 != 0x203) {
        free_list_pop_124c();
        if ((uVar4 & 0x100) == 0) {
          return 0;
        }
        iVar7 = debug_type_record_enum(sym);
        return iVar7;
      }
      *puVar1 = 0x1006;
      puVar1[2] = (ushort)g_cv_zero_attributes;
      uVar4 = (ushort)g_cv_zero_attributes;
      puVar1[2] = uVar4 | 0x80;
      uVar3 = (ushort)(((sym->detail).cls)->layout_flags3b >> 1 & 1) << 3;
      puVar1[2] = uVar3 | uVar4 & 0xfff7 | 0x80;
      puVar1[2] = (ushort)(((sym->detail).cls)->flags3e >> 7) << 8 | uVar3 | uVar4 & 0xfef7 | 0x80;
      puVar1[3] = 0;
      puVar1[4] = 0;
      uVar4 = debug_cv_unsigned_numeric_leaf(puVar1 + 5,0,0);
      sVar5 = debug_identifier_length_of_type((byte *)(uVar4 + 10 + (int)puVar1),sym);
      uVar4 = uVar4 + 10 + sVar5;
      goto LAB_1042aee8;
    }
    *puVar1 = 0x1005;
  }
  puVar1[2] = (ushort)g_cv_zero_attributes;
  uVar4 = (ushort)g_cv_zero_attributes;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[2] = uVar4 | 0x80;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  uVar4 = puVar1[2];
  uVar3 = (((sym->detail).cls)->layout_flags3b >> 1 & 1) << 3;
  puVar1[2] = uVar3 | uVar4 & 0xfff7;
  puVar1[2] = (ushort)(((sym->detail).cls)->flags3e >> 7) << 8 | uVar3 | uVar4 & 0xfef7;
  uVar4 = debug_cv_unsigned_numeric_leaf(puVar1 + 9,0,0);
  sVar5 = debug_identifier_length_of_type((byte *)(uVar4 + 0x12 + (int)puVar1),sym);
  uVar4 = uVar4 + 0x12 + sVar5;
LAB_1042aee8:
  cVar6 = cvserver_emit_type(uVar4);
  sym->type->debug_index = cVar6;
  free_list_pop_124c();
  return cVar6;
}

