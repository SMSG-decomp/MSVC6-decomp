int __cdecl class_layout_nonvirtual_base(c1_symbol *base,c1_symbol **prev_base,c1_symbol *cls)

{
  byte bVar1;
  c1_class_def_entry *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar5 = g_pack_stack->top->packing;
  uVar3 = ((base->detail).cls)->layout_flags3a & 0x3f;
  uVar7 = uVar5;
  if (uVar3 <= uVar5) {
    uVar7 = uVar3;
  }
  uVar4 = (uint)g_class_def_stack[g_class_depth].alignment;
  if ((g_class_def_stack[g_class_depth].alignment <= (ushort)uVar7) &&
     (uVar4 = uVar3, uVar5 < uVar3)) {
    uVar4 = uVar5;
  }
  g_class_def_stack[g_class_depth].alignment = (c1_u16)uVar4;
  uVar5 = class_member_padding(((base->detail).cls)->layout_flags3a & 0x3f);
  if ((((uVar5 == 0) && (*prev_base != (c1_symbol *)0x0)) &&
      (((((*prev_base)->detail).cls)->layout_flags3b & 8) != 0)) &&
     ((((base->detail).cls)->layout_flags3b & 4) != 0)) {
    g_class_def_stack[g_class_depth].offset = g_class_def_stack[g_class_depth].offset + 1;
    uVar5 = class_member_padding(((base->detail).cls)->layout_flags3a & 0x3f);
  }
  pcVar2 = g_class_def_stack + g_class_depth;
  iVar6 = g_class_def_stack[g_class_depth].offset + uVar5;
  pcVar2->offset = iVar6;
  pcVar2->offset = (int)(((base->detail).segment_class)->text + iVar6);
  if (cls != (c1_symbol *)0x0) {
    if (*prev_base == (c1_symbol *)0x0) {
      bVar1 = ((cls->detail).cls)->layout_flags3b;
      ((cls->detail).cls)->layout_flags3b =
           (((base->detail).cls)->layout_flags3b ^ bVar1) & 4 ^ bVar1;
    }
    bVar1 = ((cls->detail).cls)->layout_flags3b;
    ((cls->detail).cls)->layout_flags3b = (((base->detail).cls)->layout_flags3b ^ bVar1) & 8 ^ bVar1
    ;
  }
  *prev_base = base;
  return iVar6;
}

