c2_tuple * __fastcall x87_arith_peephole(c2_tuple *t)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_tuple *t_00;
  uint32_t uVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  int pop_op_index;
  int iVar6;
  c2_tuple *pcVar7;
  uint32_t uVar8;
  
  pcVar7 = t->prev;
  uVar8 = t->op;
  pcVar2 = t->next;
  t_00 = pcVar7->prev;
  pop_op_index = find_in_table6(uVar8,g_x87_pop_arith_op_table);
  if (pop_op_index < 0) {
    return pcVar2;
  }
  if ((((pcVar7->kind == '\f') && (uVar1 = pcVar7->type, (uVar1 & 0xf000) == 0x4000)) &&
      ((uVar3 = pcVar7->op, uVar3 == 0x60 || (uVar3 == 0x56)))) &&
     ((((uVar1 == 0x4004 || ((uVar1 == 0x4008 && (uVar3 != 0x56)))) &&
       (((pcVar7->dst->kind == '\x01' &&
         ((((((pcVar7->dst->u18).reg)->id == 0x1f && (pcVar7->src->kind != '\x01')) &&
           (pcVar4 = t->src, pcVar4->kind == '\x01')) &&
          ((((pcVar4->u18).reg)->id == 0x20 && (pcVar4 = pcVar4->next, pcVar4->kind == '\x01'))))))
        && (((pcVar4->u18).reg)->id == 0x1f)))) && (t->dst->kind == '\x01')))) {
    if (uVar3 == 0x60) {
      uVar8 = g_x87_arith_mem_operand_form_table[pop_op_index];
    }
    else {
      uVar8 = g_x87_pop_to_int_operand_form_table[pop_op_index];
    }
    pcVar7->op = uVar8;
    tuple_insert_src_after(pcVar7,pcVar7->src,pcVar4);
    tuple_swap_first_srcs(pcVar7);
    tuple_unlink_free(t);
  }
  else {
    iVar6 = x87_arith_op_index(uVar8);
    if (((iVar6 != -1) && (t_00->kind == '\f')) &&
       ((uVar1 = t_00->type, (uVar1 & 0xf000) == 0x4000 &&
        (pcVar4 = t_00->src, pcVar4 != (c2_operand *)0x0)))) {
      uVar8 = t_00->op;
      switch(uVar8) {
      case 0x56:
      case 0x60:
      case 0x7f:
      case 0x80:
      case 0x81:
      case 0x82:
      case 0x83:
      case 0x84:
      case 0x94:
        if (((pcVar7->kind == '\f') && ((pcVar7->type & 0xf000) == 0x4000)) &&
           ((pcVar5 = pcVar7->src, pcVar5 == (c2_operand *)0x0 ||
            ((pcVar5->kind != '\x01' || (((pcVar5->u18).reg)->id != 0x1f)))))) {
          switch(pcVar7->op) {
          case 0x56:
          case 0x60:
          case 0x7f:
          case 0x80:
          case 0x81:
          case 0x82:
          case 0x83:
          case 0x84:
          case 0x94:
            if ((((uVar1 == 0x4004) || ((uVar1 == 0x4008 && (uVar8 != 0x56)))) &&
                (t_00->dst->kind == '\x01')) &&
               ((((((t_00->dst->u18).reg)->id == 0x1f && (pcVar4->kind != '\x01')) &&
                 (pcVar5 = t->src, pcVar5->kind == '\x01')) &&
                (((((pcVar5->u18).reg)->id == 0x20 && (pcVar5->next->kind == '\x01')) &&
                 ((((pcVar5->next->u18).reg)->id == 0x1f && (t->dst->kind == '\x01')))))))) {
              if (uVar8 == 0x60) {
                uVar8 = g_x87_arith_mem_operand_form_table[pop_op_index];
              }
              else {
                uVar8 = g_x87_pop_to_int_operand_form_table[pop_op_index];
              }
              t->op = uVar8;
              tuple_replace_src(t,pcVar5,pcVar4);
              tuple_swap_first_srcs(t);
              tuple_unlink_free(t_00);
              return pcVar2;
            }
          }
        }
      }
    }
    if (((g_opt_favor_speed != 0) && (pcVar4 = t->src, pcVar4->kind == '\x01')) &&
       ((((pcVar4->u18).reg)->id == 0x20 &&
        ((pcVar4->next->kind == '\x01' && (((pcVar4->next->u18).reg)->id == 0x1f)))))) {
      pcVar7 = x87_fold_store_reload(t,pop_op_index);
      return pcVar7;
    }
  }
  return pcVar2;
}

