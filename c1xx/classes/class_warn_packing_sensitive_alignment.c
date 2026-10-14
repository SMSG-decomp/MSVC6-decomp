void __cdecl class_warn_packing_sensitive_alignment(uint alignment)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = g_pack_stack->top->packing;
  uVar3 = uVar2;
  if (alignment <= uVar2) {
    uVar3 = alignment;
  }
  uVar1 = (uint)g_class_def_stack[g_class_depth].alignment;
  if ((g_class_def_stack[g_class_depth].alignment <= (ushort)uVar3) &&
     (uVar1 = uVar2, alignment <= uVar2)) {
    uVar1 = alignment;
  }
  g_class_def_stack[g_class_depth].alignment = (c1_u16)uVar1;
  uVar2 = class_member_padding(alignment);
  if (uVar2 != 0) {
    if ((uint)g_pack_stack->top->packing < alignment) {
      diag_warning(4,0x79,g_class_def_stack[g_class_depth].cls);
    }
    class_append_alignment_member(uVar2);
  }
  return;
}

