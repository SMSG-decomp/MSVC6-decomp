int __thiscall conv_compare_sequences(c1_conversion *conv_a,c1_conversion *conv_b,int source_side)

{
  c1_symbol *base;
  ushort uVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  int iVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  byte bVar7;
  bool bVar8;
  
  if ((char)source_side == '\0') {
    iVar4 = conv_a->target_class;
    if (iVar4 == conv_b->target_class) {
      pcVar2 = conv_a->target;
    }
    else {
      bVar8 = iVar4 == 0xe;
      iVar4 = 6;
      if (bVar8) {
        pcVar2 = type_base(conv_a->target);
      }
      else {
        pcVar2 = conv_a->target;
      }
      if (conv_b->target_class == 0xe) {
        pcVar3 = type_base(conv_b->target);
        goto LAB_10426dd9;
      }
    }
    pcVar3 = conv_b->target;
  }
  else {
    iVar4 = conv_a->source_class;
    pcVar2 = conv_a->source;
    pcVar3 = conv_b->source;
  }
LAB_10426dd9:
  switch(iVar4) {
  case 6:
    iVar4 = conv_compare_class_derivation((char)source_side,(pcVar2->extra).cls,(pcVar3->extra).cls)
    ;
    return iVar4;
  default:
    iVar4 = conv_compare_class_derivation
                      ((char)source_side,(c1_symbol *)source_side,(c1_symbol *)source_side);
    return iVar4;
  case 8:
    pcVar2 = type_base(pcVar2);
    pcVar3 = type_base(pcVar3);
    bVar7 = (byte)pcVar2->code >> 6 & 1;
    if ((bVar7 == 0) && (((byte)pcVar3->code >> 6 & 1) == 0)) {
      iVar4 = conv_compare_class_derivation
                        ((char)source_side,(pcVar2->extra).cls,(pcVar3->extra).cls);
      return iVar4;
    }
    if (bVar7 == 0) {
      return 1;
    }
    return ((pcVar3->code & 0x40) != 0) - 1;
  case 0xc:
  case 0xd:
    uVar1 = pcVar2->code & 0x8f;
    if ((uVar1 == 0x8a) || (uVar1 == 0x8e)) {
      pcVar6 = (pcVar2->extra).cls;
    }
    else {
      pcVar6 = (c1_symbol *)0x0;
    }
    uVar1 = pcVar3->code & 0x8f;
    if ((uVar1 != 0x8a) && (uVar1 != 0x8e)) {
      iVar4 = conv_compare_class_derivation((char)source_side == '\0',pcVar6,(c1_symbol *)0x0);
      return iVar4;
    }
    iVar4 = conv_compare_class_derivation((char)source_side == '\0',pcVar6,(pcVar3->extra).cls);
    return iVar4;
  case 0xe:
    break;
  }
  pcVar2 = type_base(pcVar2);
  pcVar6 = (pcVar2->extra).cls;
  pcVar2 = type_base(pcVar3);
  base = (pcVar2->extra).cls;
  if (pcVar6 != base) {
    pcVar5 = class_lookup_qualified_member(g_current_scope,pcVar6,base,0);
    if (pcVar5 != (c1_symbol *)0x0) {
      return (-(uint)((char)source_side != '\0') & 0xfffffffe) + 1;
    }
    pcVar6 = class_lookup_qualified_member(g_current_scope,base,pcVar6,0);
    if (pcVar6 != (c1_symbol *)0x0) {
      return (-(uint)((char)source_side != '\0') & 2) - 1;
    }
  }
  return 0;
}

