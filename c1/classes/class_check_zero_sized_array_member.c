int __cdecl class_check_zero_sized_array_member(c1_symbol *member)

{
  c1_u8 *pcVar1;
  c1_u16 *pcVar2;
  char cVar3;
  c1_tag_symbol *pcVar4;
  c1_type *type;
  c1_type *pcVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  c1_symbol *pcVar10;
  undefined2 extraout_var;
  
  if (((g_struct_layouts[g_class_depth].flags & 1) != 0) &&
     (pcVar4 = g_struct_layouts[g_class_depth].tag, (pcVar4->flags4 & 1) != 0)) {
    diag_error(0xe5,pcVar4->type,pcVar4);
    pcVar1 = &(g_struct_layouts[g_class_depth].tag)->flags4;
    *pcVar1 = *pcVar1 & 0xfe;
  }
  type = member->type;
  uVar7 = type_size(type);
  if (uVar7 == 0) {
    if (((type->code & 0x8f) == 0x83) && ((type->extra).sym == (c1_symbol *)0x0)) {
      if ((g_ms_extensions == '\0') && ((g_compile_flags_c8 & 0x20000) == 0)) {
        diag_error(0x85,member);
        return 0;
      }
      diag_warning(4,200);
      member->flags4 = member->flags4 | 1;
      uVar7 = type_size(type->base);
      if (uVar7 == 0) {
        uVar7 = class_check_member_type_complete(0,type,member);
        return uVar7;
      }
    }
    else {
      cVar3 = (char)type->code;
      pcVar5 = type;
      while (cVar3 < '\0') {
        pcVar5 = pcVar5->base;
        cVar3 = (char)pcVar5->code;
      }
      if ((pcVar5->code & 0x300) == 0) {
        pcVar10 = (c1_symbol *)0x0;
      }
      else {
        pcVar10 = (pcVar5->extra).sym;
      }
      if ((pcVar10->flags1 & 1) == 0) {
        diag_error(0x4f,member,type,pcVar10);
        return 0;
      }
    }
  }
  if (((g_struct_layouts[g_class_depth].flags & 1) != 0) &&
     (g_struct_layouts[g_class_depth].bitfield_type != 0)) {
    class_close_bit_field_unit();
    iVar9 = g_class_depth;
    g_struct_layouts[g_class_depth].flags = g_struct_layouts[g_class_depth].flags & 0xfb;
    g_struct_layouts[iVar9].bitfield_bits = '\0';
  }
  uVar8 = class_member_natural_alignment(type,g_pack_stack->top->packing);
  class_warn_packing_sensitive_alignment(uVar8);
  if ((g_struct_layouts[g_class_depth].flags & 1) == 0) {
    uVar8 = 0;
    if ((uint)g_struct_layouts[g_class_depth].offset < uVar7) {
      g_struct_layouts[g_class_depth].offset = uVar7;
    }
  }
  else {
    uVar8 = g_struct_layouts[g_class_depth].offset;
    if ((member->flags4 & 1) == 0) {
      if ((uVar7 != 0) &&
         (iVar9 = fold_add_overflows(uVar8,(int)uVar8 >> 0x1f,uVar7 - 1,0,1,CONCAT22(extraout_var,4)
                                    ), iVar9 != 0)) {
        diag_error(0x59,g_struct_layouts[g_class_depth].tag,
                   (g_struct_layouts[g_class_depth].tag)->type);
        return 0;
      }
      g_struct_layouts[g_class_depth].offset = g_struct_layouts[g_class_depth].offset + uVar7;
    }
  }
  if ((type->code & 0x200) != 0) {
    if ((type->code & 0x300) == 0) {
      pcVar10 = (c1_symbol *)0x0;
    }
    else {
      pcVar10 = (type->extra).sym;
    }
    member->flags4 = (member->flags4 ^ pcVar10->flags4) & 1 ^ member->flags4;
    pcVar1 = &(g_struct_layouts[g_class_depth].tag)->flags4;
    *pcVar1 = *pcVar1 | pcVar10->flags4 & 2;
    if (((type->code & 0x20f) == 0x203) || ((pcVar10->tag_alignment & 0x100) != 0)) {
      bVar6 = 1;
    }
    else {
      bVar6 = 0;
    }
    pcVar2 = &(g_struct_layouts[g_class_depth].tag)->alignment;
    *pcVar2 = *pcVar2 | (ushort)bVar6 << 8;
  }
  uVar7 = class_member_offset_add(uVar8,0);
  return uVar7;
}

