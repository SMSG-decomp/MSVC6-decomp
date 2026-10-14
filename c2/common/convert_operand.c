c2_tuple * __fastcall convert_operand(c2_operand **v,uint16_t type,c2_tuple **anchor)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  ushort uVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  ushort uVar9;
  ushort uVar10;
  
  pcVar7 = *v;
  if (((1 << (pcVar7->kind & 0x1f) & 0x380U) != 0) &&
     (pcVar4 = constant_convert_to(pcVar7,type,(c2_tuple *)0x0), pcVar4 != (c2_operand *)0x0)) {
    *v = pcVar4;
    return (c2_tuple *)0x0;
  }
  pcVar8 = (c2_tuple *)0x0;
  uVar3 = pcVar7->type;
  if (type == uVar3) {
    return (c2_tuple *)0x0;
  }
  if ((type & 0xf000) == 0x4000) {
    if ((uVar3 & 0xf000) == 0x4000) {
      if (((uVar3 ^ type) & 0xfff) == 0) {
        return (c2_tuple *)0x0;
      }
      pcVar8 = tuple_new_unary_temp(0x15f,type,pcVar7,tuple_splice_after,*anchor);
      pcVar7 = pcVar8->dst;
      *anchor = pcVar8;
      *v = pcVar7;
      return pcVar8;
    }
    if ((uVar3 & 0xfff) < 4) {
      pcVar8 = tuple_new_unary_temp(0x15f,0x1004,pcVar7,tuple_splice_after,*anchor);
      pcVar7 = pcVar8->dst;
      *anchor = pcVar8;
      *v = pcVar7;
    }
    pcVar6 = tuple_new_unary_temp(0x15f,type,*v,tuple_splice_after,*anchor);
    pcVar7 = pcVar6->dst;
    *anchor = pcVar6;
    *v = pcVar7;
    if (pcVar8 != (c2_tuple *)0x0) {
      return pcVar8;
    }
    return pcVar6;
  }
  if ((uVar3 & 0xf000) == 0x4000) {
    pcVar8 = tuple_new_unary_temp(0x15f,type,pcVar7,tuple_splice_after,*anchor);
    uVar1 = pcVar7->kind;
    *anchor = pcVar8;
    if ((((uVar1 == '\x01') && (pcVar7->sym->cls == '\x03')) &&
        (pcVar6 = pcVar7->sym->def, pcVar6 != (c2_tuple *)0x0)) && (pcVar6->op == 0x162)) {
      tuple_replace_src(pcVar8,pcVar8->src,pcVar6->src);
      tuple_unlink(pcVar6);
      node_free((c2_node *)pcVar6);
    }
    *v = pcVar8->dst;
    return pcVar8;
  }
  if (((pcVar7->kind == '\x01') && (pcVar7->sym->cls == '\x03')) &&
     ((pcVar6 = pcVar7->sym->def, pcVar6 != (c2_tuple *)0x0 && (pcVar6->op == 0x15f)))) {
    if ((type & 0xfff) <= (uVar3 & 0xfff)) {
      uVar10 = pcVar6->src->type;
      uVar9 = uVar10 & 0xfff;
      if ((((type & 0xfff) <= uVar9) && ((1 << (byte)(uVar10 >> 0xc) & 0xeU) != 0)) && (uVar9 < 5))
      {
        pcVar2 = (*anchor)->prev;
        if ((pcVar7->flags & 0x10) == 0) {
          node_free((c2_node *)pcVar7);
        }
        pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar6->src);
        *v = pcVar7;
        pcVar7->flags = pcVar7->flags & 0xef;
        tuple_unlink(pcVar6);
        if (*anchor == pcVar6) {
          *anchor = pcVar2;
        }
        symbol_free_chain(pcVar6->dst->sym->storage);
        node_free((c2_node *)pcVar6);
        goto LAB_1070b517;
      }
    }
    uVar10 = pcVar6->src->type;
    if ((((uVar10 & 0xfff) <= (uVar3 & 0xfff)) &&
        (((uVar3 & 0xf000) != 0x2000 || ((uVar10 & 0xf000) != 0x1000)))) &&
       (((1 << (byte)(uVar3 >> 0xc) & 0xeU) == 0 || ((uVar10 & 0xf000) != 0x4000)))) {
      if ((pcVar7->flags & 0x10) == 0) {
        node_free((c2_node *)pcVar7);
        *v = pcVar6->dst;
      }
      pcVar7 = *v;
      symbol_free_chain(pcVar7->sym);
      pcVar5 = symbol_new_temp(type);
      pcVar7->sym = pcVar5;
      symbol_mark_overlapping_parts(pcVar5,pcVar6);
      pcVar4 = pcVar6->dst;
      pcVar7->type = type;
      pcVar6->type = type;
      pcVar4->type = type;
      return (c2_tuple *)0x0;
    }
  }
LAB_1070b517:
  pcVar7 = *v;
  uVar10 = type & 0xfff;
  uVar3 = pcVar7->type & 0xfff;
  if ((uVar3 < uVar10) || ((uVar10 < uVar3 && (4 < uVar3)))) {
    if ((4 < uVar10) && (uVar3 < 4)) {
      pcVar8 = convert_operand(v,0x1004,anchor);
    }
    pcVar6 = tuple_new_unary_temp(0x15f,type,*v,tuple_splice_after,*anchor);
    pcVar7 = pcVar6->dst;
    *anchor = pcVar6;
    *v = pcVar7;
    if (pcVar8 == (c2_tuple *)0x0) {
      pcVar8 = pcVar6;
    }
  }
  else {
    if ((pcVar7->flags & 0x10) != 0) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar7);
      *v = pcVar7;
    }
    pcVar7 = *v;
    pcVar7->type = type;
    if ((1 << (pcVar7->kind & 0x1f) & 6U) != 0) {
      pcVar5 = symbol_get_part(pcVar7->sym,type,type & 0xfff,0);
      pcVar7->sym = pcVar5;
      return (c2_tuple *)0x0;
    }
  }
  return pcVar8;
}

