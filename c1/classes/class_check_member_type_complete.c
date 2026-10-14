uint __cdecl class_check_member_type_complete(uint size,c1_type *type,c1_symbol *member)

{
  c1_u8 *pcVar1;
  c1_u16 *pcVar2;
  char cVar3;
  c1_type *pcVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  c1_symbol *pcVar8;
  undefined2 extraout_var;
  
  cVar3 = (char)type->code;
  pcVar4 = type;
  while (cVar3 < '\0') {
    pcVar4 = pcVar4->base;
    cVar3 = (char)pcVar4->code;
  }
  if ((pcVar4->code & 0x300) == 0) {
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    pcVar8 = (pcVar4->extra).sym;
  }
  if ((pcVar8->flags1 & 1) == 0) {
    diag_error(0x4f,member,type,pcVar8);
    return 0;
  }
  if (((g_struct_layouts[g_class_depth].flags & 1) != 0) &&
     (g_struct_layouts[g_class_depth].bitfield_type != 0)) {
    class_close_bit_field_unit();
    iVar7 = g_class_depth;
    g_struct_layouts[g_class_depth].flags = g_struct_layouts[g_class_depth].flags & 0xfb;
    g_struct_layouts[iVar7].bitfield_bits = '\0';
  }
  uVar6 = class_member_natural_alignment(type,g_pack_stack->top->packing);
  class_warn_packing_sensitive_alignment(uVar6);
  if ((g_struct_layouts[g_class_depth].flags & 1) == 0) {
    uVar6 = 0;
    if ((uint)g_struct_layouts[g_class_depth].offset < size) {
      g_struct_layouts[g_class_depth].offset = size;
    }
  }
  else {
    uVar6 = g_struct_layouts[g_class_depth].offset;
    if ((member->flags4 & 1) == 0) {
      if ((size != 0) &&
         (iVar7 = fold_add_overflows(uVar6,(int)uVar6 >> 0x1f,size - 1,0,1,CONCAT22(extraout_var,4))
         , iVar7 != 0)) {
        diag_error(0x59,g_struct_layouts[g_class_depth].tag,
                   (g_struct_layouts[g_class_depth].tag)->type);
        return 0;
      }
      g_struct_layouts[g_class_depth].offset = g_struct_layouts[g_class_depth].offset + size;
    }
  }
  if ((type->code & 0x200) != 0) {
    if ((type->code & 0x300) == 0) {
      pcVar8 = (c1_symbol *)0x0;
    }
    else {
      pcVar8 = (type->extra).sym;
    }
    member->flags4 = (member->flags4 ^ pcVar8->flags4) & 1 ^ member->flags4;
    pcVar1 = &(g_struct_layouts[g_class_depth].tag)->flags4;
    *pcVar1 = *pcVar1 | pcVar8->flags4 & 2;
    if (((type->code & 0x20f) == 0x203) || ((pcVar8->tag_alignment & 0x100) != 0)) {
      bVar5 = 1;
    }
    else {
      bVar5 = 0;
    }
    pcVar2 = &(g_struct_layouts[g_class_depth].tag)->alignment;
    *pcVar2 = *pcVar2 | (ushort)bVar5 << 8;
  }
  uVar6 = class_member_offset_add(uVar6,0);
  return uVar6;
}

