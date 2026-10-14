int debug_type_record_struct_fragment
              (int member_count,uint attributes,ushort type_code,c1_symbol *sym)

{
  ushort *puVar1;
  c1_u8 cVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  c1_symbol_x2c cVar6;
  
  debug_type_record_class_forward(sym);
  puVar1 = g_cv_record_body;
  if ((sym->flags1 & 1) == 0) {
    return 0;
  }
  attributes = CONCAT22(attributes._2_2_,(undefined2)g_cv_zero_attributes);
  member_count = 0;
  free_list_push_124c(sym);
  if (((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) &&
     (cVar2 = sym_is_deferrable(sym), cVar2 != '\0')) {
    sym_defer_emission(sym);
  }
  sym->flags1 = sym->flags1 & 0xfd;
  iVar4 = debug_emit_types_twice(sym,&member_count,(ushort *)&attributes);
  puVar1[1] = (ushort)member_count;
  if (type_code == 0x202) {
    *puVar1 = 0x1005;
    *(int *)(puVar1 + 3) = iVar4;
    puVar1[2] = (ushort)attributes;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | (ushort)attributes & 0xfff7;
    uVar5 = debug_cv_unsigned_numeric_leaf(puVar1 + 9,(sym->x28).value,0);
    iVar4 = debug_put_symbol_name((char *)((uVar5 & 0xffff) + 0x12 + (int)puVar1),sym);
    uVar5 = uVar5 + 0x12 + iVar4;
  }
  else {
    uVar5 = attributes;
    if (type_code == 0x203) {
      *puVar1 = 0x1006;
      puVar1[2] = (ushort)attributes;
      *(int *)(puVar1 + 3) = iVar4;
      uVar3 = (byte)(g_pack_stack->top->packing == 1 ^ (byte)attributes) & 1 ^ (ushort)attributes;
      puVar1[2] = uVar3;
      puVar1[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | uVar3 & 0xfff7;
      uVar5 = debug_cv_unsigned_numeric_leaf(puVar1 + 5,(sym->x28).value,0);
      iVar4 = debug_put_symbol_name((char *)((uVar5 & 0xffff) + 10 + (int)puVar1),sym);
      uVar5 = uVar5 + 10 + iVar4;
    }
  }
  cVar6 = (c1_symbol_x2c)cvserver_emit_type(uVar5);
  sym->x2c = cVar6;
  if (sym->name == g_name_unnamed) {
    sym->type->debug_index = (c1_u32)cVar6;
  }
  free_list_pop_124c();
  return (int)(sym->x2c).references;
}

