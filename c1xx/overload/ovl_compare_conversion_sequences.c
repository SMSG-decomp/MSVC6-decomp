int __thiscall
ovl_compare_conversion_sequences(c1_conversion *conv_a,c1_conversion *conv_b,int source_side)

{
  int iVar1;
  c1_conversion *pcVar2;
  c1_conversion *pcVar3;
  char cVar4;
  
  iVar1 = ovl_compare_conversion_rank(conv_a,conv_b);
  if (iVar1 != 0) {
    return iVar1;
  }
  cVar4 = (char)source_side;
LAB_10419506:
  if (((conv_a->flags4e & 0x40) != 0) || ((conv_b->flags4e & 0x40) != 0)) {
    pcVar3 = conv_a;
    if ((conv_a->flags4e & 0x40) != 0) {
      pcVar3 = conv_a->first;
    }
    pcVar2 = conv_b;
    if ((conv_b->flags4e & 0x40) != 0) {
      pcVar2 = conv_b->first;
    }
    iVar1 = ovl_compare_conversion_sequences(pcVar3,pcVar2,source_side);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = conv_compare_sequences_2(conv_a,conv_b,(char)source_side);
    return iVar1;
  }
  if (((conv_a->flags4e & 0x80) != 0) || ((conv_b->flags4e & 0x80) != 0)) {
    if ((conv_a->flags4e & 0x80) != 0) {
      conv_a = conv_a->first;
    }
    if ((conv_b->flags4e & 0x80) != 0) {
      conv_b = conv_b->first;
    }
    iVar1 = ovl_compare_conversion_sequences(conv_a,conv_b,source_side);
    return iVar1;
  }
  switch(conv_a->rank & 0xf0) {
  case 0:
  case 0x10:
  case 0x20:
    if (((conv_b->flags4f ^ conv_a->flags4f) & 4) != 0) {
      return (-(uint)((conv_a->flags4f & 4) != 0) & 0xfffffffe) + 1;
    }
    if ((((conv_a->flags4e & 0x20) != 0) || ((conv_b->flags4e & 0x20) != 0)) &&
       (iVar1 = conv_compare_sequences(conv_a,conv_b,source_side), iVar1 != 0)) {
      return iVar1;
    }
    if (((conv_a->flags4e & 2) == 0) && ((conv_b->flags4e & 2) == 0)) {
      return 0;
    }
    iVar1 = conv_compare_sequences_2(conv_a,conv_b,(char)source_side);
    if (iVar1 != 0) {
      return iVar1;
    }
    return 0;
  case 0x30:
    break;
  default:
    return 0;
  }
  if (((conv_a->via).function == (conv_b->via).function) &&
     (pcVar3 = conv_a->second, pcVar3 != (c1_conversion *)0x0)) {
    pcVar2 = conv_b->second;
    cVar4 = '\0';
    source_side = (uint)source_side._1_3_ << 8;
  }
  else {
    if (g_ms_extensions == '\0') {
      return 0;
    }
    pcVar3 = conv_a->second;
    if (pcVar3 == (c1_conversion *)0x0) {
      return 0;
    }
    pcVar2 = conv_b->second;
    if (pcVar2 == (c1_conversion *)0x0) {
      return 0;
    }
    if (cVar4 == '\0') {
      iVar1 = ovl_compare_conversion_rank(conv_a->second,conv_b->second);
      return iVar1;
    }
    cVar4 = '\x01';
    source_side = CONCAT31(source_side._1_3_,1);
  }
  iVar1 = ovl_compare_conversion_rank(pcVar3,pcVar2);
  conv_a = pcVar3;
  conv_b = pcVar2;
  if (iVar1 != 0) {
    return iVar1;
  }
  goto LAB_10419506;
}

