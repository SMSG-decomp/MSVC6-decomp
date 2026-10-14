uint __cdecl class_padding_for_offset(uint alignment,uint offset)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = g_pack_stack->top->packing;
  uVar3 = uVar2;
  if (alignment <= uVar2) {
    uVar3 = alignment;
  }
  uVar1 = 0;
  if (offset % uVar3 != 0) {
    if (alignment <= uVar2) {
      uVar2 = alignment;
    }
    uVar1 = uVar2 - offset % uVar3;
  }
  return uVar1;
}

