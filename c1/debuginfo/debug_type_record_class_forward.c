c1_u32 __cdecl debug_type_record_class_forward(c1_symbol *sym)

{
  ushort uVar1;
  ushort *puVar2;
  c1_u8 cVar3;
  uint uVar4;
  int iVar5;
  c1_u32 cVar6;
  
  puVar2 = g_cv_record_body;
  uVar1 = sym->type->code;
  cVar6 = sym->type->debug_index;
  if (cVar6 == 0) {
    if (sym->name == g_name_unnamed) {
      cVar6 = debug_type_record_struct(sym);
      sym->type->debug_index = cVar6;
      return cVar6;
    }
    free_list_push_124c(sym);
    if ((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) {
      cVar3 = sym_is_deferrable(sym);
      if (cVar3 != '\0') {
        sym_defer_emission(sym);
      }
    }
    sym->flags1 = sym->flags1 & 0xfd;
    puVar2[1] = 0;
    if (uVar1 == 0x202) {
      *puVar2 = 0x1005;
      puVar2[2] = (ushort)g_cv_zero_attributes;
      uVar1 = (ushort)g_cv_zero_attributes;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[2] = uVar1 | 0x80;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | uVar1 & 0xfff7 | 0x80;
      uVar4 = debug_cv_unsigned_numeric_leaf(puVar2 + 9,0,0);
      iVar5 = debug_put_symbol_name((char *)((uVar4 & 0xffff) + 0x12 + (int)puVar2),sym);
      uVar4 = uVar4 + 0x12 + iVar5;
    }
    else {
      if (uVar1 != 0x203) {
        free_list_pop_124c();
        if ((uVar1 & 0x100) != 0) {
          cVar6 = debug_type_record_enum(sym);
          return cVar6;
        }
        return 0;
      }
      *puVar2 = 0x1006;
      puVar2[2] = (ushort)g_cv_zero_attributes;
      uVar1 = (ushort)g_cv_zero_attributes;
      puVar2[2] = uVar1 | 0x80;
      puVar2[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | uVar1 & 0xfff7 | 0x80;
      puVar2[3] = 0;
      puVar2[4] = 0;
      uVar4 = debug_cv_unsigned_numeric_leaf(puVar2 + 5,0,0);
      iVar5 = debug_put_symbol_name((char *)((uVar4 & 0xffff) + 10 + (int)puVar2),sym);
      uVar4 = uVar4 + 10 + iVar5;
    }
    cVar6 = cvserver_emit_type(uVar4);
    sym->type->debug_index = cVar6;
    free_list_pop_124c();
  }
  return cVar6;
}

