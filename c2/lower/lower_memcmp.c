void __fastcall lower_memcmp(c2_tuple *t)

{
  bool bVar1;
  uint16_t type;
  uint8_t uVar2;
  uint uVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_symbol *pcVar6;
  uint32_t uVar7;
  c2_operand *pcVar8;
  c2_operand *pcVar9;
  c2_fe_symbol *label_sym;
  int iVar10;
  c2_operand *local_1c;
  c2_operand *local_18;
  c2_operand *local_14;
  c2_operand *local_10;
  c2_operand *local_c;
  c2_tuple *local_8;
  c2_operand *local_4;
  
  bVar1 = false;
  pcVar8 = t->dst;
  pcVar9 = t->src->next->next->sym->def->src;
  uVar3 = 1 << (pcVar8->kind & 0x1f) & 6;
  if ((((uVar3 != 0) && (pcVar8->sym->def != (c2_tuple *)0x0)) ||
      (((uVar3 != 0 &&
        (((pcVar6 = pcVar8->sym, pcVar6->cls == '\x03' && (pcVar6->def == (c2_tuple *)0x0)) &&
         ((pcVar6->flags7 & 2) != 0)))) &&
       ((pcVar9->kind != '\a' || ((pcVar9->u18).reg != (c2_symbol *)0x0 || pcVar9->tag != 0)))))) &&
     ((pcVar4 = find_next_use_of_dst(t,&local_1c), pcVar4 != (c2_tuple *)0x0 &&
      (((pcVar5 = tuple_next_real_before_boundary(t), pcVar4 == pcVar5 && (pcVar4->op == 0x17d)) &&
       ((pcVar8 = pcVar4->src->next, pcVar8->kind == '\a' &&
        ((pcVar8->u18).reg == (c2_symbol *)0x0 && pcVar8->tag == 0)))))))) {
    local_1c = (c2_operand *)find_next_use_of_dst(pcVar4,&local_4);
    uVar2 = x86_fixed_reg_class((c2_tuple *)local_1c);
    if ((uVar2 == '\x01') || (uVar2 == '\x02')) {
      bVar1 = true;
      tuple_unlink_free(pcVar4);
    }
  }
  type = 0x1001;
  if (((bVar1) && (pcVar9->kind == '\a')) && ((t->u24).intrinsic_flag == 0)) {
    pcVar6 = (c2_symbol *)(pcVar9->u18).lo;
    if (pcVar6 != (c2_symbol *)0x0) {
      if (((uint)pcVar6 & 3) == 0) {
        type = 0x1004;
        pcVar6 = (c2_symbol *)((int)((int)&pcVar6->fe + ((int)pcVar6 >> 0x1f & 3U)) >> 2);
        (pcVar9->u18).reg = pcVar6;
      }
      else if (((uint)pcVar6 & 1) == 0) {
        type = 0x1002;
        pcVar6 = (c2_symbol *)((int)pcVar6 / 2);
        (pcVar9->u18).lo = (uint32_t)pcVar6;
      }
    }
    if (pcVar6 == (c2_symbol *)0x1) {
      iVar10 = 0;
      do {
        if (iVar10 == 0) {
          pcVar8 = t->src;
        }
        else {
          pcVar8 = t->src->next;
        }
        (pcVar8->u18).reg = pcVar8->sym;
        pcVar4 = pcVar8->sym->def;
        pcVar4->dst->u18 = (c2_operand_u18)pcVar4->dst->sym;
        uVar7 = load_op_for_operand(pcVar4->src);
        iVar10 = iVar10 + 1;
        pcVar4->op = uVar7;
      } while (iVar10 < 2);
      tuple_unlink_free(t->src->next->next->sym->def);
      if (g_opt_global == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = tuple_get_memeffect_alias(t);
      }
      pcVar8 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,t->src,(c2_operand *)0x0,uVar7);
      pcVar4 = tuple_new_unary_temp(1,type,pcVar8,tuple_insert_before,t);
      if (g_opt_global == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = tuple_second_memeffect_src_value(t);
      }
      pcVar8 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,t->src->next,(c2_operand *)0x0,uVar7);
      pcVar4 = tuple_new_src_only(0x2f,type,pcVar4->dst,tuple_insert_after,pcVar4);
      tuple_append_src(pcVar4,pcVar8);
      pcVar8 = local_1c;
      goto LAB_1077157f;
    }
  }
  local_10 = lower_arg_push_value(t,t->src);
  local_14 = lower_arg_push_value(t,t->src->next);
  local_18 = lower_arg_push_value(t,t->src->next->next);
  label_sym = label_symbol_new();
  local_8 = tuple_new_label(label_sym);
  pcVar9 = operand_new_temp(0x1004);
  pcVar4 = build_zero_extend_int64(pcVar9,t->prev,0,1);
  local_c = tuple_add_flags_result(pcVar4);
  if (bVar1) {
    pcVar5 = tuple_new_pseudo(0x19e,0x1004);
    tuple_append_src(pcVar5,pcVar9);
    tuple_insert_after(pcVar4,pcVar5);
    pcVar8 = local_1c;
  }
  else {
    pcVar8 = operand_new_temp_sym(0x1004);
    pcVar5 = tuple_new(1,0x1004,pcVar8,pcVar9,tuple_insert_after,pcVar4);
  }
  if (g_opt_global == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = tuple_get_memeffect_alias(t);
  }
  pcVar4 = emit_string_insn(0x10f,type,&local_10,&local_14,&local_18,pcVar5,0,0,uVar7);
  tuple_append_src(pcVar4,local_c);
  if (g_opt_global != 0) {
    uVar7 = tuple_second_memeffect_src_value(t);
    pcVar9 = operand_new_memeffect(uVar7);
    tuple_append_src(pcVar4,pcVar9);
  }
LAB_1077157f:
  pcVar9 = tuple_add_flags_result(pcVar4);
  pcVar5 = local_8;
  if (bVar1) {
    tuple_replace_src((c2_tuple *)local_1c,local_4,pcVar9);
    return;
  }
  pcVar4 = tuple_new_branch(0xf,'\x01',(c2_node *)local_8,pcVar9,pcVar4,tuple_insert_after,pcVar4);
  pcVar4 = emit_sbb_mask(pcVar4);
  pcVar4 = tuple_new(1,0x1004,pcVar8,pcVar4->dst,tuple_insert_after,pcVar4);
  tuple_insert_after(pcVar4,pcVar5);
  pcVar9 = t->dst;
  pcVar4 = tuple_new(1,0x1004,pcVar9,pcVar8,tuple_insert_after,pcVar4->next);
  if (((1 << (pcVar9->kind & 0x1f) & 6U) != 0) &&
     (pcVar6 = pcVar9->sym, pcVar6->def != (c2_tuple *)0x0)) {
    if (pcVar6->storage->part_next != (c2_symbol *)0x0) {
      symbol_mark_overlapping_parts(pcVar6,pcVar4);
      return;
    }
    pcVar6->def = pcVar4;
    return;
  }
  lower_tuple(pcVar4);
  return;
}

