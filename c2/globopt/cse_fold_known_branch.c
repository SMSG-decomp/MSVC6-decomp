c2_tuple * __fastcall
cse_fold_known_branch
          (c2_tuple *cmp,c2_tuple *br,c2_operand *a,c2_block *b,c2_function *fn,int taken)

{
  c2_symbol *sym;
  c2_operand *src;
  c2_tuple *pcVar1;
  c2_block *to;
  
  if (br->kind == '\x11') {
    node_list_remove_rank(br,(int)cmp);
    tuple_delete(cmp);
    if (taken == 0) {
      pcVar1 = *(c2_tuple **)((int)&br->src->sym->u30 + 2);
      to = (pcVar1->u14).block;
      if (to == (c2_block *)0x0) {
        pcVar1 = tuple_find_prev_of_kind(pcVar1,'\x19');
        to = (pcVar1->u14).block;
      }
      if (g_next_tuple_cursor == br) {
        g_next_tuple_cursor = br->next;
      }
      tuple_delete(br);
    }
    else {
      to = b->next;
      br->op = 0x186;
      tuple_remove_src(br,a);
      *(undefined1 *)&br->type = 0;
    }
    remove_loop_back_edge(b,to,fn);
    return (c2_tuple *)0x0;
  }
  if (taken == 0) {
    src = br->src->next->next;
  }
  else {
    src = br->src->next;
  }
  pcVar1 = tuple_new(0x15b,br->type,br->dst,src,tuple_insert_after,br);
  number_assignment(pcVar1,1);
  if (((1 << (pcVar1->dst->kind & 0x1f) & 6U) != 0) &&
     (sym = pcVar1->dst->sym, sym->def != (c2_tuple *)0x0)) {
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = pcVar1;
    }
    else {
      symbol_mark_overlapping_parts(sym,pcVar1);
    }
  }
  tuple_delete(cmp);
  tuple_delete(br);
  g_next_tuple_cursor = pcVar1->next;
  return pcVar1;
}

