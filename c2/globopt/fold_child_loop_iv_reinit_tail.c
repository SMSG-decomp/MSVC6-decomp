void __cdecl
fold_child_loop_iv_reinit_tail
          (c2_loop *child,c2_tuple *candidate,c2_loop *child_loop,c2_loop *parent_loop)

{
  c2_operand *op;
  c2_symbol *iv;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  longlong lVar3;
  c2_tuple *pcVar4;
  c2_tuple *t;
  c2_operand *pcVar5;
  longlong lVar6;
  
  do {
    op = candidate->dst;
    pcVar4 = find_store_matching_operand(op,child);
    iv = candidate->src->sym;
    t = iv_increment_tuple(iv);
    if ((t != (c2_tuple *)0x0) && (pcVar4->op == t->op)) {
      pcVar1 = pcVar4->src->next;
      pcVar5 = iv_find_copy_source(t->src->next,parent_loop);
      child = child_loop;
      if ((pcVar1->kind == '\a') &&
         (((pcVar5->kind == '\a' && (pcVar2 = child_loop->trip_count, pcVar2->kind == '\a')) &&
          (lVar6 = __allmul((pcVar2->u18).lo,pcVar2->tag,(pcVar1->u18).lo,pcVar1->tag),
          lVar3._0_4_ = pcVar5->u18, lVar3._4_4_ = pcVar5->tag, lVar6 == lVar3)))) {
        pcVar4 = t->next;
        tuple_replace_src(pcVar4,pcVar4->src,op);
        symbol_remove_use(iv,t);
        tuple_unlink_free(t);
        enter_tuple_in_expression_table(pcVar4,0);
      }
    }
    candidate = iv_worklist_pop();
  } while (candidate != (c2_tuple *)0x0);
  do {
    do {
      child = child->next;
      if (child == (c2_loop *)0x0) {
        return;
      }
    } while ((child->u30).iv_update_clones == (c2_list_cell *)0x0);
    reset_iv_worklists();
    collect_iv_candidates(child,5);
    pcVar4 = iv_worklist_pop();
  } while (pcVar4 == (c2_tuple *)0x0);
  fold_child_loop_iv_reinit_tail(child,pcVar4,child,parent_loop);
  return;
}

