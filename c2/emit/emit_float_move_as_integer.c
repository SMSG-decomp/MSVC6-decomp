void __fastcall emit_float_move_as_integer(c2_tuple *t)

{
  uint16_t uVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  int iVar4;
  c2_float_const *value;
  c2_const_operand *pcVar5;
  uint16_t type;
  
  uVar1 = t->type;
  if (uVar1 == 0x4004) {
    type = 0x1004;
  }
  else {
    if (uVar1 != 0x4008) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lowerflt.c",0x4ca);
    }
    type = 0x1008;
    if ((g_opt_global != 0) && (g_opt_favor_speed != 0)) {
      pcVar3 = t;
      if (t->kind != '\x19') {
        pcVar3 = tuple_find_prev_of_kind(t,'\x19');
      }
      iVar4 = int_power(5,(int)((pcVar3->u14).block)->loop_depth);
      g_double_align_bias = g_double_align_bias + iVar4;
    }
  }
  pcVar2 = t->src;
  t->type = type;
  value = float_constant_value_of(pcVar2);
  if (value != (c2_float_const *)0x0) {
    pcVar5 = float_const_to_int_bits(value,type);
    tuple_replace_src(t,pcVar2,pcVar5);
  }
  pcVar2 = t->src->next;
  if ((pcVar2 != (c2_operand *)0x0) &&
     (value = float_constant_value_of(pcVar2), value != (c2_float_const *)0x0)) {
    pcVar5 = float_const_to_int_bits(value,type);
    tuple_replace_src(t,pcVar2,pcVar5);
  }
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((pcVar2->type == uVar1) && ((1 << (pcVar2->kind & 0x1f) & 0x380U) == 0)) {
      operand_set_type(pcVar2,type);
    }
  }
  for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if (pcVar2->type == uVar1) {
      operand_set_type(pcVar2,type);
    }
  }
  return;
}

