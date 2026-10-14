int __fastcall analyze_loop_exit_test(c2_loop *loop,c2_function *fn)

{
  c2_operand *iv;
  c2_loop_exit *pcVar1;
  uint32_t uVar2;
  c2_operand *pcVar3;
  int iVar4;
  c2_block *block;
  c2_tuple *t;
  c2_tuple *local_14;
  int local_10;
  c2_block *local_c;
  c2_function *local_8;
  c2_block *local_4;
  
  t = (c2_tuple *)0x0;
  local_4 = loop->first;
  block = loop->last;
  pcVar1 = loop->exits;
  iVar4 = 0;
  local_10 = 1;
  local_14 = (c2_tuple *)0x0;
  local_c = block;
  local_8 = fn;
  if (pcVar1 != (c2_loop_exit *)0x0) {
    do {
      if (pcVar1->block != block) goto LAB_10745b0d;
      pcVar1 = pcVar1->next;
      iVar4 = iVar4 + 1;
    } while (pcVar1 != (c2_loop_exit *)0x0);
    if (((iVar4 == 1) && (iVar4 = loop_header_has_extra_preds(loop), iVar4 == 0)) &&
       (t = get_latch_exit_compare(loop->last,&local_14), t != (c2_tuple *)0x0)) {
      uVar2 = is_induction_variable_operand(t->src);
      if ((uVar2 == 0) || (uVar2 = is_loop_invariant_operand(t->src->next), uVar2 == 0)) {
        uVar2 = is_induction_variable_operand(t->src->next);
        if ((uVar2 == 0) || (uVar2 = is_loop_invariant_operand(t->src), uVar2 == 0))
        goto LAB_10745b0d;
        tuple_swap_first_srcs(t);
        branch_swap_condition(local_14);
      }
      iv = t->src;
      pcVar3 = (c2_operand *)node_clone((c2_node *)iv->next);
      uVar2 = is_loop_invariant_operand(pcVar3);
      block = local_c;
      if (((uVar2 != 0) && ((1 << (byte)(pcVar3->type >> 0xc) & 0xeU) != 0)) &&
         (pcVar3 = compute_loop_trip_count(loop,iv,t,pcVar3,local_14), block = local_c,
         pcVar3 != (c2_operand *)0x0)) {
        if (pcVar3->kind == '\a') {
          if (((pcVar3->u18).reg == (c2_symbol *)0x0 && pcVar3->tag == 0) ||
             (((pcVar3->u18).reg == (c2_symbol *)0x1 && (pcVar3->tag == 0)))) {
            node_free((c2_node *)pcVar3);
            local_10 = 0;
            block = local_c;
            goto LAB_10745b0d;
          }
        }
        pcVar3 = operand_claim(pcVar3);
        loop->trip_count = pcVar3;
        if ((iv->type & 0xfff) < 4) {
          bitset_set(g_narrow_iv_syms,iv->sym->id);
          loop->exit_compare = t;
          return local_10;
        }
        goto LAB_10745b20;
      }
    }
  }
LAB_10745b0d:
  loop->trip_count = (c2_operand *)0x0;
  if (local_10 == 0) {
    tuple_unlink_free(t);
    branch_free(local_14);
    remove_loop_back_edge(block,local_4,local_8);
    loop->exits = (c2_loop_exit *)0x0;
    return 0;
  }
LAB_10745b20:
  loop->exit_compare = t;
  return local_10;
}

