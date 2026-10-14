void __cdecl class_layout_bitfield_member(c1_symbol *sym,c1_u16 type_code,c1_u8 append)

{
  c1_u8 *pcVar1;
  char *pcVar2;
  ushort uVar3;
  c1_symbol *pcVar4;
  void *pvVar5;
  int iVar6;
  c1_u16 cVar7;
  uint uVar8;
  uint uVar9;
  
  cVar7 = type_code;
  _type_code = (uint)type_code;
  if (((g_class_def_stack[g_class_depth].flags & 8) != 0) &&
     (pcVar4 = g_class_def_stack[g_class_depth].cls, (pcVar4->flags5 & 1) != 0)) {
    diag_error(0xe5,pcVar4->type,pcVar4);
    pcVar1 = &(g_class_def_stack[g_class_depth].cls)->flags5;
    *pcVar1 = *pcVar1 & 0xfe;
  }
  if (((((byte)cVar7 & 0x1f) != 0x13) && ((cVar7 & 0x100) == 0)) && ((cVar7 & 0x10) == 0)) {
    if (((cVar7 & 0xfff) == 0x802) || ((cVar7 & 0xfff) == 0x801)) {
      (sym->x28).bytes.depth = '\x01';
    }
    else {
      diag_error(0x96,sym);
      sym->type = g_type_unsigned_int;
      _type_code = 0x2013;
    }
  }
  if ((char)sym->type->code < '\0') {
    diag_error(0x21,sym);
  }
  uVar8 = (uint)(sym->x28).bytes.depth;
  if (uVar8 == 0) {
    if (sym->name != g_name_alignment_member) {
      diag_error(0x95,sym);
    }
    if (g_class_def_stack[g_class_depth].bitfield_type == 0) {
      return;
    }
  }
  pcVar2 = &g_type_rank_table + (_type_code & 0xf);
  uVar9 = (char)(&g_type_rank_table)[_type_code & 0xf] * 8;
  if (uVar9 < uVar8) {
    diag_error(0x22,sym);
    uVar8 = uVar9;
  }
  if ((g_class_def_stack[g_class_depth].flags & 8) == 0) {
    if (g_class_def_stack[g_class_depth].offset < (int)*pcVar2) {
      g_class_def_stack[g_class_depth].offset = (int)*pcVar2;
    }
  }
  else {
    uVar3 = g_class_def_stack[g_class_depth].bitfield_type;
    if (uVar3 != 0) {
      if (((*pcVar2 == (&g_type_rank_table)[uVar3 & 0xf]) && (uVar8 != 0)) &&
         (g_class_def_stack[g_class_depth].bit_offset + uVar8 <= uVar9)) goto LAB_1042fd22;
      if (uVar3 != 0) {
        class_close_bit_field_unit();
      }
    }
    iVar6 = g_class_depth;
    g_class_def_stack[g_class_depth].bit_offset = '\0';
    g_class_def_stack[iVar6].flags = g_class_def_stack[iVar6].flags & 0xdf;
    class_warn_packing_sensitive_alignment((int)*pcVar2);
  }
LAB_1042fd22:
  pvVar5 = g_name_alignment_member;
  g_class_def_stack[g_class_depth].bitfield_type = -(ushort)(uVar8 != 0) & (ushort)_type_code;
  if (sym->name != pvVar5) {
    if (append != '\0') {
      class_append_member(sym);
    }
    (sym->x28).bytes.depth = (c1_u8)uVar8;
    iVar6 = g_class_depth;
    g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags | 0x20;
    (sym->x28).bytes.bit_position = g_class_def_stack[iVar6].bit_offset;
  }
  iVar6 = g_class_depth;
  if ((g_class_def_stack[g_class_depth].flags & 8) == 0) {
    (sym->detail).cls = (c1_class_record *)0x0;
    return;
  }
  g_class_def_stack[g_class_depth].bit_offset =
       g_class_def_stack[g_class_depth].bit_offset + (c1_u8)uVar8;
  sym->detail = (c1_symbol_detail)g_class_def_stack[iVar6].offset;
  return;
}

