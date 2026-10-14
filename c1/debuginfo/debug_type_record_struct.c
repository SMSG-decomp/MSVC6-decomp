int __cdecl debug_type_record_struct(c1_symbol *tag)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  ushort *puVar4;
  c1_symbol *sym;
  c1_u8 cVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  c1_symbol *length;
  c1_symbol_x2c cVar9;
  c1_symbol_cell *pcVar10;
  c1_u32 cVar11;
  int in_ECX;
  ushort uVar12;
  
  sym = tag;
  puVar4 = g_cv_record_body;
  pcVar2 = tag->type;
  cVar1 = (char)pcVar2->code;
  pcVar3 = pcVar2;
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  uVar6 = pcVar3->code;
  pcVar10 = (tag->x2c).references;
  if (pcVar10 == (c1_symbol_cell *)0x0) {
    if ((uVar6 & 0x100) != 0) {
      cVar11 = debug_type_record_enum(tag);
      return cVar11;
    }
    if ((pcVar2->debug_index == 0) && (tag->name != g_name_unnamed)) {
      iVar7 = debug_type_record_struct_fragment(in_ECX,(uint)tag,uVar6,tag);
      return iVar7;
    }
    if ((tag->flags1 & 1) == 0) {
      return 0;
    }
    tag = (c1_symbol *)CONCAT22(tag._2_2_,(undefined2)g_cv_zero_attributes);
    uVar12 = 0;
    free_list_push_124c(sym);
    if (((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) &&
       (cVar5 = sym_is_deferrable(sym), cVar5 != '\0')) {
      sym_defer_emission(sym);
    }
    sym->flags1 = sym->flags1 & 0xfd;
    iVar7 = debug_emit_types_twice(sym,(int *)&stack0xfffffffc,(ushort *)&tag);
    puVar4[1] = uVar12;
    if (uVar6 == 0x202) {
      *puVar4 = 0x1005;
      *(int *)(puVar4 + 3) = iVar7;
      puVar4[2] = (ushort)tag;
      puVar4[7] = 0;
      puVar4[8] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | (ushort)tag & 0xfff7;
      uVar8 = debug_cv_unsigned_numeric_leaf(puVar4 + 9,(sym->x28).value,0);
      iVar7 = debug_put_symbol_name((char *)((uVar8 & 0xffff) + 0x12 + (int)puVar4),sym);
      length = (c1_symbol *)(uVar8 + 0x12 + iVar7);
    }
    else {
      length = tag;
      if (uVar6 == 0x203) {
        *puVar4 = 0x1006;
        puVar4[2] = (ushort)tag;
        *(int *)(puVar4 + 3) = iVar7;
        uVar6 = (byte)(g_pack_stack->top->packing == 1 ^ (byte)tag) & 1 ^ (ushort)tag;
        puVar4[2] = uVar6;
        puVar4[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | uVar6 & 0xfff7;
        uVar8 = debug_cv_unsigned_numeric_leaf(puVar4 + 5,(sym->x28).value,0);
        iVar7 = debug_put_symbol_name((char *)((uVar8 & 0xffff) + 10 + (int)puVar4),sym);
        length = (c1_symbol *)(uVar8 + 10 + iVar7);
      }
    }
    cVar9.debug_object = (c1_symbol *)cvserver_emit_type(length);
    sym->x2c = cVar9;
    if (sym->name == g_name_unnamed) {
      sym->type->debug_index = (c1_u32)cVar9;
    }
    free_list_pop_124c();
    pcVar10 = (sym->x2c).references;
  }
  return (int)pcVar10;
}

