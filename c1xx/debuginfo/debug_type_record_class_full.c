int __cdecl debug_type_record_class_full(c1_symbol *sym)

{
  c1_type *pcVar1;
  c1_type *pcVar2;
  ushort *puVar3;
  c1_symbol *sym_00;
  char cVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  c1_symbol *pcVar8;
  c1_u32 cVar9;
  int local_8;
  int local_4;
  
  sym_00 = sym;
  pcVar1 = sym->type;
  cVar4 = (char)pcVar1->code;
  pcVar2 = pcVar1;
  while (cVar4 < '\0') {
    pcVar2 = pcVar2->base;
    cVar4 = (char)pcVar2->code;
  }
  uVar5 = pcVar2->code;
  cVar9 = ((sym->detail).cls)->debug_index;
  if (cVar9 != 0) {
    return cVar9;
  }
  if ((uVar5 & 0x100) != 0) {
    iVar7 = debug_type_record_enum(sym);
    return iVar7;
  }
  if ((pcVar1->debug_index == 0) && (sym->name != g_name_unnamed)) {
    debug_type_record_class_forward(sym);
  }
  puVar3 = g_cv_record_body;
  if ((sym_00->flags2 & 4) == 0) {
    return 0;
  }
  sym = (c1_symbol *)CONCAT22(sym._2_2_,(undefined2)g_cv_zero_attributes);
  local_8 = 0;
  local_4 = 0;
  free_list_push_124c(sym_00);
  if (((((g_pch_use_only != 0) && ((sym_00->kind & 0x20) == 0)) &&
       ((g_compile_flags_cc & 0x100000) == 0)) &&
      (((g_compile_flags_cc & 0x20) == 0 && ((g_compile_flags_c8 & 0x10000000) == 0)))) &&
     (cVar4 = sym_is_deferrable(sym_00), cVar4 != '\0')) {
    sym_defer_emission(sym_00);
  }
  sym_00->flags2 = sym_00->flags2 & 0xf7;
  iVar7 = debug_emit_types_twice(sym_00,&local_8,(ushort *)&sym);
  if (((((sym_00->detail).cls)->layout_flags3a & 0x40) != 0) &&
     ((uVar5 == 0x202 || (uVar5 == 0x201)))) {
    local_4 = debug_type_record_vtshape(sym_00);
  }
  puVar3[1] = (ushort)local_8;
  if (uVar5 == 0x201) {
    *puVar3 = 0x1004;
  }
  else {
    if (uVar5 != 0x202) {
      pcVar8 = sym;
      if (uVar5 == 0x203) {
        *puVar3 = 0x1006;
        puVar3[2] = (ushort)sym;
        *(int *)(puVar3 + 3) = iVar7;
        uVar6 = (byte)(g_pack_stack->top->packing == 1 ^ (byte)sym) & 1 ^ (ushort)sym;
        puVar3[2] = uVar6;
        uVar5 = (((sym_00->detail).cls)->layout_flags3b >> 1 & 1) << 3;
        puVar3[2] = uVar5 | uVar6 & 0xfff7;
        puVar3[2] = (ushort)(((sym_00->detail).cls)->flags3e >> 7) << 8 | uVar5 | uVar6 & 0xfef7;
        uVar5 = debug_cv_unsigned_numeric_leaf(puVar3 + 5,((sym_00->detail).cls)->size,0);
        uVar6 = debug_identifier_length_of_type((byte *)(uVar5 + 10 + (int)puVar3),sym_00);
        pcVar8 = (c1_symbol *)(uVar5 + 10 + (uint)uVar6);
      }
      goto LAB_1043bd40;
    }
    *puVar3 = 0x1005;
  }
  puVar3[2] = (ushort)sym;
  *(int *)(puVar3 + 3) = iVar7;
  *(int *)(puVar3 + 7) = local_4;
  uVar5 = puVar3[2];
  iVar7 = g_pack_stack->top->packing;
  puVar3[5] = 0;
  puVar3[6] = 0;
  uVar5 = (byte)(iVar7 == 1 ^ (byte)uVar5) & 1 ^ uVar5;
  puVar3[2] = uVar5;
  uVar6 = (((sym_00->detail).cls)->layout_flags3b >> 1 & 1) << 3;
  puVar3[2] = uVar6 | uVar5 & 0xfff7;
  puVar3[2] = (ushort)(((sym_00->detail).cls)->flags3e >> 7) << 8 | uVar6 | uVar5 & 0xfef7;
  uVar5 = debug_cv_unsigned_numeric_leaf(puVar3 + 9,((sym_00->detail).cls)->size,0);
  uVar6 = debug_identifier_length_of_type((byte *)(uVar5 + 0x12 + (int)puVar3),sym_00);
  pcVar8 = (c1_symbol *)(uVar5 + 0x12 + (uint)uVar6);
LAB_1043bd40:
  cVar9 = cvserver_emit_type((ushort)pcVar8);
  ((sym_00->detail).cls)->debug_index = cVar9;
  if (sym_00->name == g_name_unnamed) {
    sym_00->type->debug_index = ((sym_00->detail).cls)->debug_index;
  }
  free_list_pop_124c();
  return ((sym_00->detail).cls)->debug_index;
}

