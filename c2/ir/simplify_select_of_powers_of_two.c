c2_tuple * __fastcall simplify_select_of_powers_of_two(c2_tuple *t,c2_tuple *parent)

{
  ushort uVar1;
  uint16_t type;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_const_operand *pcVar5;
  c2_operand *value;
  uint32_t op;
  uint32_t diff_lo;
  uint32_t bit_lo;
  int32_t bit_hi;
  c2_operand *pcVar6;
  uint uVar7;
  ushort uVar8;
  int64_t iVar9;
  int64_t iVar10;
  c2_operand *and_src;
  
  pcVar4 = t->src;
  if (pcVar4->op != 0x17d) {
    return (c2_tuple *)0x0;
  }
  if ((1 << (byte)(pcVar4->type >> 0xc) & 0xeU) == 0) {
    return (c2_tuple *)0x0;
  }
  if ((t->u20).cc == '\x02') {
    pcVar3 = pcVar4->next;
    pcVar6 = pcVar3->next;
  }
  else {
    if ((t->u20).cc != '\x01') {
      return (c2_tuple *)0x0;
    }
    pcVar6 = pcVar4->next;
    pcVar3 = pcVar6->next;
  }
  if ((1 << (pcVar3->kind & 0x1f) & 0x380U) == 0) {
    return (c2_tuple *)0x0;
  }
  if ((1 << (pcVar6->kind & 0x1f) & 0x380U) == 0) {
    return (c2_tuple *)0x0;
  }
  diff_lo = (pcVar6->u18).lo ^ (pcVar3->u18).lo;
  uVar7 = pcVar6->tag ^ pcVar3->tag;
  if (diff_lo != 0 || uVar7 != 0) {
    if ((int)uVar7 < 0) {
      return (c2_tuple *)0x0;
    }
    if (((int)uVar7 < 1) && (diff_lo == 0)) {
      return (c2_tuple *)0x0;
    }
    if ((diff_lo - 1 & diff_lo) != 0 || (uVar7 - (diff_lo == 0) & uVar7) != 0) {
      return (c2_tuple *)0x0;
    }
  }
  value = (pcVar4->u18).children;
  if (((1 << (value->kind & 0x1f) & 0x380U) == 0) ||
     ((value->u18).reg != (c2_symbol *)0x0 || value->tag != 0)) {
    pcVar2 = value->next;
    if ((1 << (pcVar2->kind & 0x1f) & 0x380U) == 0) {
      return (c2_tuple *)0x0;
    }
    if ((pcVar2->u18).reg != (c2_symbol *)0x0 || pcVar2->tag != 0) {
      return (c2_tuple *)0x0;
    }
  }
  else {
    value = value->next;
  }
  if (value->op != 0x172) {
    return (c2_tuple *)0x0;
  }
  and_src = (value->u18).children;
  if ((1 << (and_src->kind & 0x1f) & 0x380U) == 0) {
LAB_1074d7a6:
    pcVar2 = and_src->next;
    if ((1 << (pcVar2->kind & 0x1f) & 0x380U) == 0) {
      return (c2_tuple *)0x0;
    }
    bit_hi = pcVar2->tag;
    bit_lo = (pcVar2->u18).lo;
    if (bit_hi < 0) {
      return (c2_tuple *)0x0;
    }
    if ((bit_hi < 1) && (bit_lo == 0)) {
      return (c2_tuple *)0x0;
    }
    if ((bit_lo - 1 & bit_lo) != 0 || (bit_hi - (uint)(bit_lo == 0) & bit_hi) != 0) {
      return (c2_tuple *)0x0;
    }
  }
  else {
    bit_hi = and_src->tag;
    bit_lo = (and_src->u18).lo;
    if ((bit_hi < 0) ||
       (((bit_hi < 1 && (bit_lo == 0)) ||
        ((bit_lo - 1 & bit_lo) != 0 || (bit_hi - (uint)(bit_lo == 0) & bit_hi) != 0))))
    goto LAB_1074d7a6;
  }
  if (bit_lo == 0 && bit_hi == 0) {
    return (c2_tuple *)0x0;
  }
  tuple_detach_src((c2_node *)pcVar4,value);
  if (((int)pcVar3->tag <= (int)pcVar6->tag) &&
     (((int)pcVar3->tag < (int)pcVar6->tag || ((pcVar3->u18).reg < (pcVar6->u18).reg)))) {
    pcVar5 = operand_new_intconst(value->type,bit_lo,bit_hi);
    value = (c2_operand *)
            tuple_new_binary_temp
                      (0x174,value->type,value,pcVar5,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_unlink_mem_subops((c2_tuple *)value);
    *(uint8_t *)&value->x12 = '\x02';
  }
  uVar1 = t->src->type;
  uVar8 = t->type;
  if ((t->type & 0xfff) <= (uVar1 & 0xfff)) {
    uVar8 = uVar1;
  }
  uVar8 = uVar8 & 0xfff | 0x2000;
  pcVar4 = value;
  if (uVar8 != uVar1) {
    pcVar4 = operand_new_temp(uVar8);
    pcVar4 = (c2_operand *)
             tuple_new_unary_temp(0x15f,uVar8,pcVar4,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_replace_src((c2_tuple *)pcVar4,(pcVar4->u18).children,value);
    *(uint8_t *)&pcVar4->x12 = '\x02';
  }
  if ((int)uVar7 < bit_hi) {
LAB_1074d8a1:
    iVar9 = shift_loop_noop(bit_lo,bit_hi);
    iVar10 = shift_loop_noop(diff_lo,uVar7);
    pcVar5 = operand_new_intconst
                       (uVar8,(uint32_t)(iVar9 - iVar10),
                        (int32_t)((ulonglong)(iVar9 - iVar10) >> 0x20));
    op = 0x177;
  }
  else {
    if (((int)uVar7 <= bit_hi) && (diff_lo <= bit_lo)) {
      if ((bit_hi < (int)uVar7) || ((bit_hi <= (int)uVar7 && (bit_lo <= diff_lo))))
      goto LAB_1074d8e7;
      goto LAB_1074d8a1;
    }
    iVar9 = shift_loop_noop(bit_lo,bit_hi);
    iVar10 = shift_loop_noop(diff_lo,uVar7);
    pcVar5 = operand_new_intconst
                       (uVar8,(uint32_t)(iVar10 - iVar9),
                        (int32_t)((ulonglong)(iVar10 - iVar9) >> 0x20));
    op = 0x171;
  }
  pcVar4 = (c2_operand *)
           tuple_new_binary_temp(op,uVar8,pcVar4,pcVar5,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  tuple_unlink_mem_subops((c2_tuple *)pcVar4);
  *(uint8_t *)&pcVar4->x12 = '\x02';
LAB_1074d8e7:
  type = t->type;
  value = pcVar4;
  if (pcVar4->type != type) {
    value = operand_new_temp(type);
    value = (c2_operand *)tuple_new_unary_temp(0x15f,type,value,(c2_insert_fn *)0x0,(c2_tuple *)0x0)
    ;
    tuple_replace_src((c2_tuple *)value,(value->u18).children,pcVar4);
    *(uint8_t *)&value->x12 = '\x02';
  }
  uVar7 = (pcVar6->u18).lo & (pcVar3->u18).lo;
  bit_hi = pcVar6->tag & pcVar3->tag;
  if (uVar7 != 0 || bit_hi != 0) {
    pcVar5 = operand_new_intconst(type,uVar7,bit_hi);
    value = (c2_operand *)
            tuple_new_binary_temp(0x173,type,value,pcVar5,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_unlink_mem_subops((c2_tuple *)value);
    *(uint8_t *)&value->x12 = '\x02';
  }
  if (parent != (c2_tuple *)0x0) {
    tuple_replace_src(parent,(c2_operand *)t,value);
    return (c2_tuple *)value;
  }
  node_free((c2_node *)t);
  return (c2_tuple *)value;
}

