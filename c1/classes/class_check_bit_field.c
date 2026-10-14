void __cdecl class_check_bit_field(c1_symbol *member,ushort type_code)

{
  c1_u8 *pcVar1;
  char *pcVar2;
  ushort uVar3;
  c1_tag_symbol *pcVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = type_code;
  _type_code = (uint)type_code;
  if (((g_struct_layouts[g_class_depth].flags & 1) != 0) &&
     (pcVar4 = g_struct_layouts[g_class_depth].tag, (pcVar4->flags4 & 1) != 0)) {
    diag_error(0xe5,pcVar4->type,pcVar4);
    pcVar1 = &(g_struct_layouts[g_class_depth].tag)->flags4;
    *pcVar1 = *pcVar1 & 0xfe;
  }
  if (((byte)uVar3 & 0x1f) != 0x13) {
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      if ((uVar3 & 0x10) == 0) {
        diag_error(0x96,member);
        member->type = g_type_unsigned_int;
LAB_106330a9:
        _type_code = 0x2013;
      }
      else if ('\x04' < (char)(&g_type_rank_table)[uVar3 & 0xf]) {
        diag_warning(4,0xd6);
      }
    }
    else {
      if ((uVar3 & 0x10) == 0) {
        diag_warning(1,0xf,member);
        member->type = g_type_unsigned_int;
        goto LAB_106330a9;
      }
      diag_warning(4,0xd6);
    }
  }
  if ((char)member->type->code < '\0') {
    diag_error(0x21,member);
  }
  uVar7 = (uint)(member->x28).bytes.depth;
  if (uVar7 == 0) {
    if (member->name != g_name_alignment_member) {
      diag_error(0x95,member);
    }
    if (g_struct_layouts[g_class_depth].bitfield_type == 0) {
      return;
    }
  }
  pcVar2 = &g_type_rank_table + (_type_code & 0xf);
  uVar8 = (char)(&g_type_rank_table)[_type_code & 0xf] * 8;
  if (uVar8 < uVar7) {
    diag_error(0x22,member);
    uVar7 = uVar8;
  }
  if ((g_struct_layouts[g_class_depth].flags & 1) == 0) {
    if (g_struct_layouts[g_class_depth].offset < (int)*pcVar2) {
      g_struct_layouts[g_class_depth].offset = (int)*pcVar2;
    }
  }
  else {
    uVar3 = g_struct_layouts[g_class_depth].bitfield_type;
    if (uVar3 != 0) {
      if (((*pcVar2 == (&g_type_rank_table)[uVar3 & 0xf]) && (uVar7 != 0)) &&
         (g_struct_layouts[g_class_depth].bitfield_bits + uVar7 <= uVar8)) goto LAB_106113de;
      if (uVar3 != 0) {
        class_close_bit_field_unit();
      }
    }
    iVar6 = g_class_depth;
    g_struct_layouts[g_class_depth].bitfield_bits = '\0';
    g_struct_layouts[iVar6].flags = g_struct_layouts[iVar6].flags & 0xfb;
    class_warn_packing_sensitive_alignment((int)*pcVar2);
  }
LAB_106113de:
  pvVar5 = g_name_alignment_member;
  g_struct_layouts[g_class_depth].bitfield_type = -(ushort)(uVar7 != 0) & (ushort)_type_code;
  if (member->name != pvVar5) {
    class_append_member(member);
    (member->x28).bytes.depth = (c1_u8)uVar7;
    iVar6 = g_class_depth;
    g_struct_layouts[g_class_depth].flags = g_struct_layouts[g_class_depth].flags | 4;
    (member->x28).bytes.bit_position = g_struct_layouts[iVar6].bitfield_bits;
  }
  iVar6 = g_class_depth;
  if ((g_struct_layouts[g_class_depth].flags & 1) == 0) {
    member->detail = (void *)0x0;
    return;
  }
  g_struct_layouts[g_class_depth].bitfield_bits =
       g_struct_layouts[g_class_depth].bitfield_bits + (c1_u8)uVar7;
  member->detail = (void *)g_struct_layouts[iVar6].offset;
  return;
}

