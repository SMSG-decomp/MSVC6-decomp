c2_operand * __fastcall sr_materialize_operand_in_preheader(c2_operand *op,c2_loop *loop)

{
  uint16_t type;
  c2_symbol *sym;
  c2_tuple *anchor;
  c2_operand *src;
  c2_tuple *pcVar1;
  
  if (((1 << (op->kind & 0x1f) & 0x380U) == 0) && (op->kind != 3)) {
    free_pending_tuple_list();
    anchor = g_iv_scratch_tail;
    type = op->type;
    src = materialize_value_in_preheader(type,op,g_iv_scratch_tail,0);
    tuple_new_unary_temp(0x15b,type,src,tuple_insert_before,anchor);
    g_cur_avail_set = loop->preheader->set50;
    pcVar1 = g_iv_scratch_list_head;
    if (g_iv_scratch_list_head != g_iv_scratch_tail->next) {
      do {
        if ((pcVar1->flags & 1) != 0) {
          cse_replace_operands(pcVar1);
        }
        pcVar1 = pcVar1->next;
      } while (pcVar1 != g_iv_scratch_tail->next);
    }
    g_pending_tuples = (c2_list_cell *)0x0;
    pcVar1 = anchor->prev;
    sym = pcVar1->dst->sym;
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = (c2_tuple *)0x0;
    }
    else {
      symbol_mark_overlapping_parts(sym,(c2_tuple *)0x0);
    }
    resimplify_tuple(pcVar1);
    pcVar1 = anchor->prev;
    symbol_free_chain(pcVar1->dst->sym);
    return pcVar1->src;
  }
  return op;
}

