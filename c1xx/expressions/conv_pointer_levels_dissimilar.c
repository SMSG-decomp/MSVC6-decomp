char __thiscall
conv_pointer_levels_dissimilar(c1_conversion *conv,c1_type *to,c1_type *from,char top_level)

{
  char cVar1;
  ushort uVar2;
  c1_vector *pcVar3;
  int iVar4;
  int iVar5;
  c1_type *pcVar6;
  c1_symbol *pcVar7;
  c1_type *pcVar8;
  ushort uVar9;
  byte bVar10;
  byte local_8;
  
  local_8 = 1;
  if (conv->mode == '\x03') {
    pcVar3 = vector_new(5,5);
    (conv->via).cv_levels = pcVar3;
    conv->flags4f = conv->flags4f | 1;
  }
  while( true ) {
    pcVar8 = to;
    if ((to->code & 0x8f) == 0x83) {
      pcVar8 = type_skip_arrays(to->base);
    }
    pcVar6 = from;
    if ((from->code & 0x8f) == 0x83) {
      pcVar6 = type_skip_arrays(from->base);
    }
    if ((((byte)pcVar6->flags ^ (byte)pcVar8->flags) & 0x18) != 0) break;
    if ((to->code & 0x8f) == 0x83) {
      type_skip_arrays(to->base);
    }
    if ((from->code & 0x8f) == 0x83) {
      type_skip_arrays(from->base);
    }
    uVar9 = to->code & 0x8f;
    if ((uVar9 == 0x8a) || (uVar9 == 0x8e)) {
      uVar2 = from->code & 0x8f;
      if ((uVar2 == 0x8a) || (uVar2 == 0x8e)) {
        pcVar7 = (from->extra).cls;
      }
      else {
        pcVar7 = (c1_symbol *)0x0;
      }
      if ((to->extra).cls != pcVar7) {
        cVar1 = conv_pointer_levels_dissimilar_return_true();
        return cVar1;
      }
    }
    if ((top_level == '\0') || (g_ms_extensions == '\0')) {
      bVar10 = 0;
    }
    else {
      bVar10 = 1;
    }
    pcVar8 = to;
    if (uVar9 == 0x83) {
      pcVar8 = type_skip_arrays(to->base);
    }
    top_level = '\0';
    local_8 = local_8 & ((byte)pcVar8->flags >> 5 & 1 | bVar10);
    to = type_base(to);
    from = type_base(from);
    conv_compare_level_qualifiers(conv,to,from,local_8);
    iVar4 = type_category(to);
    iVar5 = type_category(from);
    if (iVar4 != iVar5) {
      return '\x01';
    }
    switch(iVar4) {
    case 8:
    case 10:
    case 0xc:
    case 0xd:
      break;
    default:
      cVar1 = type_compare(to,from,2);
      return '\x01' - (cVar1 != '\0');
    }
  }
  return '\x01';
}

