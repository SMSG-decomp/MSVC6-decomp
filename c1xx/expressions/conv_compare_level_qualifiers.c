void __thiscall
conv_compare_level_qualifiers(c1_conversion *conv,c1_type *to,c1_type *from,char outer_const)

{
  byte bVar1;
  ushort uVar2;
  c1_type *pcVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar5 = 0;
  pcVar3 = to;
  if ((to->code & 0x8f) == 0x83) {
    pcVar3 = type_skip_arrays(to->base);
  }
  uVar4 = (byte)pcVar3->flags & 0x60;
  pcVar3 = from;
  if ((from->code & 0x8f) == 0x83) {
    pcVar3 = type_skip_arrays(from->base);
  }
  uVar2 = (byte)pcVar3->flags & 0x60;
  if (uVar4 != uVar2) {
    uVar5 = ~uVar2 & uVar4;
    if (uVar5 != 0) {
      bVar1 = conv->flags4e;
      conv->flags4e = bVar1 | 2;
      if (outer_const == '\0') {
        conv->flags4e = bVar1 | 6;
      }
    }
    if ((uVar2 & ~uVar4) != 0) {
      conv->flags4e = conv->flags4e | 4;
    }
  }
  if ((to->code & 0x8f) == 0x83) {
    to = type_skip_arrays(to->base);
  }
  uVar4 = to->flags & 0x100;
  if ((from->code & 0x8f) == 0x83) {
    from = type_skip_arrays(from->base);
  }
  uVar2 = from->flags & 0x100;
  if (uVar4 != uVar2) {
    conv->flags4e = conv->flags4e | 2;
    uVar5 = uVar5 | ~uVar2 ^ ~uVar4;
  }
  if ((conv->flags4f & 1) != 0) {
    vector_push((conv->via).cv_levels,(void *)(uint)uVar5);
    return;
  }
  conv->cv_added = uVar5;
  return;
}

