void __fastcall
rewrite_iv_uses_from_survivor
          (c2_loop *loop,c2_tuple *dead_init,c2_tuple *survivor_init,c2_operand *diff,
          int *survivor_uses)

{
  uint16_t uVar1;
  c2_operand *node;
  c2_symbol *s;
  c2_symbol *sym;
  c2_tuple *pcVar2;
  c2_operand *op;
  c2_tuple *t;
  int iVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  
  node = survivor_init->dst;
  s = dead_init->dst->sym;
  sym = node->sym;
  if (sym != s) {
    pcVar2 = symbol_pop_use(s);
    while (pcVar2 != (c2_tuple *)0x0) {
      if (pcVar2->flags13 == '\x04') {
        tuple_unlink_free(pcVar2);
      }
      else if ((diff->kind == '\a') && ((diff->u18).reg == (c2_symbol *)0x0 && diff->tag == 0)) {
        pcVar4 = find_src_symbol_ref(pcVar2,s);
        while (pcVar4 != (c2_operand *)0x0) {
          uVar1 = pcVar4->type;
          pcVar5 = (c2_operand *)node_clone((c2_node *)node);
          operand_retype_keep_sets(pcVar5,uVar1);
          tuple_replace_src(pcVar2,pcVar4,pcVar5);
          enter_tuple_in_expression_table(pcVar2,0);
          add_symbol_loop_use(sym,pcVar2);
          *survivor_uses = *survivor_uses + 1;
          pcVar4 = find_src_symbol_ref(pcVar2,s);
        }
      }
      else {
        pcVar4 = find_src_symbol_ref(pcVar2,s);
        while (pcVar4 != (c2_operand *)0x0) {
          uVar1 = pcVar4->type;
          pcVar5 = (c2_operand *)node_clone((c2_node *)node);
          operand_retype_keep_sets(pcVar5,uVar1);
          op = (c2_operand *)node_clone((c2_node *)diff);
          operand_retype_keep_sets(op,uVar1);
          t = tuple_new_cse_binary(0x16d,uVar1,pcVar5,op,tuple_insert_before,pcVar2);
          t->line = pcVar2->line;
          tuple_replace_src(pcVar2,pcVar4,t->dst);
          enter_tuple_in_expression_table(pcVar2,0);
          add_symbol_loop_use(sym,t);
          *survivor_uses = *survivor_uses + 1;
          pcVar4 = find_src_symbol_ref(pcVar2,s);
        }
      }
      pcVar2 = symbol_pop_use(s);
    }
    pcVar2 = symbol_pop_def(s);
    tuple_unlink_free(pcVar2);
    if ((((s->u18).expr != (c2_cse_expr *)0x0) && (((s->u30).sizeopt.width_facts & 1) != 0)) &&
       (iVar3 = range_src_may_alias(loop->preheader->head,&loop->preheader->end->next,dead_init->dst
                                   ), iVar3 == 0)) {
      tuple_unlink_free(dead_init);
    }
  }
  return;
}

