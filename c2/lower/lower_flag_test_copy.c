void __fastcall lower_flag_test_copy(c2_tuple *t)

{
  byte bVar1;
  uint16_t type;
  uint uVar2;
  c2_symbol *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  
  pcVar6 = t->src;
  if ((pcVar6->kind != '\a') &&
     ((t->dst->kind != '\x01' || ((t->dst->u18).reg != g_reg_symbols + 0x1f)))) {
    if ((pcVar6->kind == '\x01') &&
       ((pcVar6->sym->cls == '\x03' && (pcVar4 = pcVar6->sym->def, pcVar4 != (c2_tuple *)0x0)))) {
      uVar2 = pcVar4->op;
      if (((uVar2 == 0) || (0x143 < uVar2)) || ((g_x86_op_flags[uVar2] & 2) == 0)) {
        pcVar6 = pcVar6->next;
        t->op = 1;
        tuple_remove_src(t,pcVar6);
        return;
      }
LAB_1077b6e7:
      pcVar6 = t->dst;
      if (((pcVar6->kind != '\x01') || (pcVar6->sym->cls != '\x03')) ||
         (pcVar6->sym->def == (c2_tuple *)0x0)) {
        type = pcVar6->type;
        pcVar5 = operand_new_temp(type);
        tuple_new(1,type,pcVar6,pcVar5,tuple_insert_after,t);
        tuple_replace_dst(t,t->dst,pcVar5);
        pcVar5->sym->def = t;
      }
      enforce_two_address_form(t);
      pcVar6 = operand_new_temp_in_reg(0x42,0x8000);
      pcVar5 = find_dst_clobbering_reg(pcVar4,g_reg_symbols + 0x42);
      pcVar3 = pcVar6->sym;
      if (pcVar3->storage->part_next == (c2_symbol *)0x0) {
        pcVar3->def = pcVar4;
      }
      else {
        symbol_mark_overlapping_parts(pcVar3,pcVar4);
      }
      if (pcVar5 != (c2_operand *)0x0) {
        tuple_replace_dst(pcVar4,pcVar5,pcVar6);
        tuple_append_src(t,pcVar6);
        return;
      }
      tuple_append_dst(pcVar4,pcVar6);
      tuple_append_src(t,pcVar6);
      return;
    }
    pcVar4 = tuple_new_unary_temp(1,pcVar6->type,pcVar6,tuple_insert_before,t);
    tuple_replace_src(t,t->src,pcVar4->dst);
    bVar1 = pcVar4->src->kind;
    if (((1 << (bVar1 & 0x1f) & 6U) != 0) &&
       ((pcVar3 = pcVar4->src->sym, pcVar3->cls == '\x03' && (pcVar3->def == (c2_tuple *)0x0)))) {
      pcVar4 = pcVar4->prev;
      if ((pcVar4->flags & 1) != 0) {
        do {
          pcVar6 = pcVar4->dst;
          if (((pcVar6 != (c2_operand *)0x0) && (pcVar6->kind == '\x02')) &&
             (pcVar6->sym->storage == pcVar3->storage)) break;
          pcVar4 = pcVar4->prev;
        } while ((pcVar4->flags & 1) != 0);
        if ((((pcVar4->flags & 1) != 0) && (uVar2 = pcVar4->op, uVar2 != 0)) &&
           ((uVar2 < 0x144 && ((g_x86_op_flags[uVar2] & 2) != 0)))) goto LAB_1077b6e7;
      }
      t->op = 1;
      tuple_remove_src(t,t->src->next);
      return;
    }
    if (bVar1 == 6) {
      tuple_legalize_mem_operands(pcVar4);
    }
    t->op = 1;
    tuple_remove_src(t,t->src->next);
  }
  return;
}

