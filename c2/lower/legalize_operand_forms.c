c2_tuple * __fastcall legalize_operand_forms(c2_tuple *t)

{
  uint uVar1;
  c2_symbol *pcVar2;
  c2_operand *new_op;
  c2_tuple *t_00;
  c2_operand *pcVar3;
  ushort uVar4;
  bool bVar5;
  c2_symbol *storage;
  
  uVar1 = t->op;
  if (uVar1 < 0x21) {
    if (uVar1 == 0x20) {
      lower_divide_operands(t,g_divide_high_reg_by_size[t->type >> 1 & 0x7ff],0);
      return t;
    }
    switch(uVar1) {
    case 6:
      goto switchD_1071293d_caseD_6;
    case 0xc:
    case 0xd:
      pcVar3 = operand_list_find_reg(t->src,g_reg_symbols + 5);
      if (pcVar3 == (c2_operand *)0x0) {
        pcVar3 = operand_new_hardreg(5,0x1004);
        tuple_append_src(t,pcVar3);
      }
      pcVar3 = operand_list_find_reg(t->dst,g_reg_symbols + 5);
      if (pcVar3 == (c2_operand *)0x0) {
        pcVar3 = operand_new_hardreg(5,0x1004);
        tuple_append_dst(t,pcVar3);
        return t;
      }
      break;
    case 0xe:
      lower_call_site(t);
      return t;
    case 0xf:
      pcVar3 = t->src->next;
      if (((pcVar3->kind == '\x01') && (pcVar3->sym->cls == '\x03')) &&
         (pcVar3->sym->def != (c2_tuple *)0x0)) {
        flags_bind_compare_result(t,pcVar3);
        return t;
      }
      break;
    case 0x1f:
      lower_divide_operands(t,g_divide_high_reg_by_size[t->type >> 1 & 0x7ff],1);
      return t;
    }
  }
  else {
    if (0x11a < uVar1) {
      if (uVar1 != 0x15a) {
        if (uVar1 != 0x176) {
          return t;
        }
        bVar5 = (t->type & 0xf000) != 0x2000;
        if (bVar5) {
          t->op = 0x20;
        }
        else {
          t->op = 0x1f;
        }
        lower_divide_operands(t,g_divide_low_reg_by_size[t->type >> 1 & 0x7ff],(uint)!bVar5);
        return t;
      }
      if ((t->dst->u18).reg != g_reg_symbols + 5) {
        return t;
      }
      pcVar3 = t->src;
      uVar4 = pcVar3->type;
      t->type = t->type & 0xf004 | 4;
      uVar4 = uVar4 & 0xf004 | 4;
      pcVar3->type = uVar4;
      if ((1 << (pcVar3->kind & 0x1f) & 6U) == 0) {
        return t;
      }
      if (uVar4 == pcVar3->sym->type) {
        return t;
      }
      pcVar2 = symbol_get_part(pcVar3->sym,uVar4,4,0);
      pcVar3->sym = pcVar2;
      return t;
    }
    if (uVar1 == 0x11a) {
      if (t->dst->kind == '\x01') {
        return t;
      }
      t_00 = tuple_new_unary_temp(0x11a,t->type,t->src,tuple_insert_before,t);
      t->op = 1;
      tuple_replace_src(t,t->src,t_00->dst);
      pcVar3 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(t_00,pcVar3);
      return t;
    }
    if (uVar1 != 0x22) {
      if (uVar1 < 0x25) {
        return t;
      }
      if (0x2b < uVar1) {
        return t;
      }
      pcVar3 = t->src->next;
      if (pcVar3->kind != '\x01') {
        return t;
      }
      if ((pcVar3->type & 0xfff) == 1) {
        return t;
      }
      pcVar3->type = 0x1001;
      (pcVar3->u18).reg = (c2_symbol *)0x107acd18;
      pcVar2 = symbol_get_part(pcVar3->sym,0x1001,1,0);
      pcVar3->sym = pcVar2;
      return t;
    }
switchD_1071293d_caseD_6:
    tuple_move_eax_src_last(t);
    if ((t->type & 0xfff) == 1) {
      pcVar3 = t->dst;
      storage = g_reg_symbols + 9;
      pcVar2 = symbol_get_part(pcVar3->sym,0x1002,2,0);
      new_op = operand_new_reg(0x149,0x1002,pcVar2,storage);
      tuple_replace_dst(t,pcVar3,new_op);
      return t;
    }
  }
  return t;
}

