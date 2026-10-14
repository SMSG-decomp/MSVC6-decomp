c2_operand * __fastcall
build_trip_count_expression
          (c2_loop *loop,c2_operand *init,c2_operand *limit,c2_operand *step,int inclusive,
          uint32_t update_dominates_exit,c2_tuple *cmp)

{
  c2_tuple *at;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_const_operand *pcVar5;
  int iVar6;
  code *insert_fn_00;
  uint8_t uVar7;
  c2_tuple *pcVar8;
  c2_tuple *local_10;
  int32_t limit_lo;
  int32_t init_lo;
  c2_tuple *local_4;
  c2_insert_fn *insert_fn;
  int32_t step_lo;
  uint16_t cmp_type;
  
  pcVar3 = step;
  cmp_type = cmp->type;
  free_pending_tuple_list();
  if (init->kind == '\a') {
    init_lo = (init->u18).lo;
  }
  if (limit->kind == '\a') {
    limit_lo = (limit->u18).lo;
  }
  uVar7 = '\x03';
  step = (c2_operand *)0x0;
  step_lo = (pcVar3->u18).lo;
  pcVar1 = (c2_operand *)node_clone((c2_node *)limit);
  pcVar2 = (c2_operand *)node_clone((c2_node *)init);
  pcVar1 = trip_count_is_nonzero(pcVar2,pcVar1,uVar7);
  if (pcVar1 != (c2_operand *)0x0) {
    uVar7 = '\x03';
    pcVar5 = operand_new_intconst(0x1004,0,0);
    pcVar2 = (c2_operand *)node_clone((c2_node *)pcVar3);
    pcVar2 = trip_count_is_nonzero(pcVar2,pcVar5,uVar7);
    if (pcVar2 != (c2_operand *)0x0) {
      step = trip_count_is_nonzero(pcVar1,pcVar2,'\x02');
    }
  }
  free_pending_tuple_list();
  at = g_iv_scratch_tail;
  pcVar1 = convert_operand_wrapper(0x2004,init,g_iv_scratch_tail);
  pcVar2 = convert_operand_wrapper(0x2004,limit,at);
  pcVar3 = convert_operand_wrapper(0x2004,pcVar3,at);
  if (((pcVar1->kind == '\a') && (pcVar2->kind == '\a')) &&
     (iVar6 = add_overflows((int)(pcVar2->u18).reg - (pcVar1->u18).lo,(pcVar3->u18).lo,1,4),
     iVar6 != 0)) {
    return (c2_operand *)0x0;
  }
  pcVar4 = tuple_new_binary_temp(0x16e,0x2004,pcVar2,pcVar1,tuple_insert_before,at);
  pcVar4 = tuple_new_binary_temp(0x16d,0x2004,pcVar4->dst,pcVar3,tuple_insert_before,at);
  if (inclusive != 0) {
    insert_fn = tuple_insert_before;
    pcVar8 = at;
    pcVar5 = operand_new_intconst(0x2004,1,0);
    pcVar4 = tuple_new_binary_temp(0x16e,0x2004,pcVar4->dst,pcVar5,insert_fn,pcVar8);
  }
  pcVar4 = tuple_new_binary_temp(0x175,0x2004,pcVar4->dst,pcVar3,tuple_insert_before,at);
  if (update_dominates_exit != 0) {
    insert_fn_00 = tuple_insert_before;
    pcVar8 = at;
    pcVar5 = operand_new_intconst(0x2004,1,0);
    pcVar4 = tuple_new_binary_temp(0x16d,0x2004,pcVar4->dst,pcVar5,insert_fn_00,pcVar8);
  }
  clone_temp_def_tree(pcVar4->dst->sym,&local_10,&local_4);
  free_pending_tuple_list();
  while (local_10 != (c2_tuple *)0x0) {
    pcVar4 = local_10->next;
    tuple_insert_before(at,local_10);
    local_10 = pcVar4;
  }
  pcVar4 = at->prev;
  pcVar3 = operand_new_sym(0x14a,pcVar4->dst->type,pcVar4->dst->sym);
  pcVar3->sym->def = (c2_tuple *)0x0;
  tuple_replace_dst(pcVar4,pcVar4->dst,pcVar3);
  resimplify_tuple(pcVar4);
  if (at->prev->op == 0x15b) {
    pcVar3 = at->prev->src;
    uVar7 = pcVar3->kind;
    if (((uVar7 != '\x02') && (uVar7 != '\x03')) && (uVar7 != '\a')) goto LAB_10762a3a;
  }
  else {
LAB_10762a3a:
    pcVar4 = g_iv_scratch_list_head->next;
    if (pcVar4 != g_iv_scratch_tail) {
      do {
        if (pcVar4->op != 0x15b) {
          enter_tuple_in_expression_table(pcVar4,1);
        }
        pcVar4 = pcVar4->next;
      } while (pcVar4 != g_iv_scratch_tail);
    }
    tuple_unlink_free(at->prev);
    pcVar3 = at->prev->dst;
  }
  pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar3);
  if (pcVar3->kind == '\a') {
    if (step == (c2_operand *)0x0) {
      node_free((c2_node *)pcVar3);
      pcVar3 = (c2_operand *)0x0;
    }
    else if (((step->u18).reg == (c2_symbol *)0x1) && (step->tag == 0)) {
      (pcVar3->u18).reg = (c2_symbol *)0x0;
      pcVar3->tag = 0;
    }
  }
  if ((cmp->flags & 0x80) == 0) {
    if (pcVar3->kind == '\a') {
      if ((pcVar3->u18).reg == (c2_symbol *)0x0 && pcVar3->tag == 0) {
        (pcVar3->u18).lo = 1;
        pcVar3->tag = 0;
      }
      goto LAB_10762957;
    }
  }
  else {
LAB_10762957:
    if (pcVar3 == (c2_operand *)0x0) goto LAB_10762979;
    if (pcVar3->kind == '\a') {
LAB_10762aa6:
      if ((pcVar3->u18).lo * step_lo - ((limit_lo - init_lo) + update_dominates_exit) == 0)
      goto LAB_10762979;
    }
    else if (step_lo == 1) {
      if (pcVar3->kind != '\a') goto LAB_10762979;
      goto LAB_10762aa6;
    }
    if ((char)cmp_type != '\x02') goto LAB_10762979;
  }
  node_free((c2_node *)pcVar3);
  pcVar3 = (c2_operand *)0x0;
LAB_10762979:
  free_pending_tuple_list();
  return pcVar3;
}

