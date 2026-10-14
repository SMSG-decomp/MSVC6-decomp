int __fastcall expand_div_by_constant(c2_tuple *anchor)

{
  uint divisor;
  c2_symbol *sym;
  uint uVar1;
  c2_div_magic *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_const_operand *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  uint32_t uVar8;
  uint16_t type;
  int offset;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  pcVar6 = anchor->src;
  divisor = (pcVar6->next->u18).lo;
  uVar1 = (divisor ^ (int)divisor >> 0x1f) - ((int)divisor >> 0x1f);
  if ((0 < (int)uVar1) && ((uVar1 & uVar1 - 1) == 0)) {
    return 0;
  }
  if ((anchor->type & 0xf000) != 0x1000) {
    expand_udiv_by_constant(anchor);
    return 1;
  }
  pcVar2 = signed_div_magic(divisor);
  pcVar3 = operand_new_temp_sym(0x1004);
  mark_operand_register_candidate(pcVar3);
  pcVar4 = tuple_new((-(uint)(pcVar6->type != 0x1004) & 4) + 0x15b,0x1004,pcVar3,pcVar6,
                     tuple_insert_before,anchor);
  pcVar6 = pcVar4->dst;
  insert_fn = tuple_insert_before;
  pcVar4 = anchor;
  pcVar5 = operand_new_intconst(0x1004,pcVar2->multiplier,pcVar2->multiplier >> 0x1f);
  pcVar4 = tuple_new_binary_temp(0x170,0x1004,pcVar6,pcVar5,insert_fn,pcVar4);
  pcVar3 = pcVar4->dst;
  if (((int)divisor < 1) || (-1 < pcVar2->multiplier)) {
    if ((-1 < (int)divisor) || (pcVar2->multiplier < 1)) goto LAB_10766e20;
    uVar8 = 0x16e;
  }
  else {
    uVar8 = 0x16d;
  }
  pcVar4 = tuple_new_binary_temp(uVar8,0x1004,pcVar3,pcVar6,tuple_insert_before,anchor);
  pcVar3 = pcVar4->dst;
LAB_10766e20:
  uVar8 = pcVar2->shift;
  if (uVar8 != 0) {
    insert_fn = tuple_insert_before;
    pcVar4 = anchor;
    pcVar5 = operand_new_intconst(0x1004,uVar8,(int)uVar8 >> 0x1f);
    pcVar4 = tuple_new_binary_temp(0x177,0x1004,pcVar3,pcVar5,insert_fn,pcVar4);
    pcVar3 = pcVar4->dst;
  }
  pcVar6 = operand_new_temp_sym(0x1004);
  mark_operand_register_candidate(pcVar6);
  pcVar4 = tuple_new(0x15b,0x1004,pcVar6,pcVar3,tuple_insert_before,anchor);
  pcVar6 = pcVar4->dst;
  insert_fn = tuple_insert_before;
  pcVar4 = anchor;
  pcVar5 = operand_new_intconst(0x1004,0x1f,0);
  pcVar4 = tuple_new_binary_temp(0x177,0x2004,pcVar6,pcVar5,insert_fn,pcVar4);
  pcVar7 = tuple_new_binary_temp(0x16d,0x1004,pcVar6,pcVar4->dst,tuple_insert_before,anchor);
  pcVar6 = anchor->dst;
  insert_fn_00 = tuple_insert_before;
  type = pcVar6->type;
  pcVar4 = anchor;
  if ((type & 0xfff) == 4) {
    pcVar3 = pcVar7->dst;
    type = 0x1004;
  }
  else {
    offset = 0;
    pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar7->dst);
    pcVar3 = operand_retype(pcVar3,type,offset);
  }
  pcVar4 = tuple_new(0x15b,type,pcVar6,pcVar3,insert_fn_00,pcVar4);
  if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (sym = pcVar6->sym, sym->def != (c2_tuple *)0x0))
  {
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = pcVar4;
      tuple_unlink_free(anchor);
      return 1;
    }
    symbol_mark_overlapping_parts(sym,pcVar4);
  }
  tuple_unlink_free(anchor);
  return 1;
}

