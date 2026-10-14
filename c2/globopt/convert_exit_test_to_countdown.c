void __fastcall convert_exit_test_to_countdown(c2_loop *loop,c2_function *fn)

{
  c2_tuple *anchor;
  c2_list_cell *pcVar1;
  c2_operand *pcVar2;
  c2_const_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *local_4;
  c2_insert_fn *insert_fn;
  
  if (loop->trip_count == (c2_operand *)0x0) {
    return;
  }
  anchor = loop->exit_compare;
  pcVar5 = anchor->src->sym;
  if (anchor->src->next == (c2_operand *)0x0) {
    pcVar4 = iv_increment_tuple(pcVar5);
    if (pcVar4->op == 0x16d) {
      pcVar2 = pcVar4->src->next;
      if ((pcVar2->kind == '\a') && (((pcVar2->u18).lo & pcVar2->tag) == 0xffffffff)) {
        return;
      }
    }
    else {
      pcVar2 = pcVar4->src->next;
      if (((pcVar2->kind == '\a') && ((pcVar2->u18).reg == (c2_symbol *)0x1)) && (pcVar2->tag == 0))
      {
        return;
      }
    }
  }
  pcVar1 = pcVar5->uses;
  while( true ) {
    if (pcVar1 == (c2_list_cell *)0x0) {
      if ((pcVar5->defs != (c2_list_cell *)0x0) && (pcVar5->defs->next == (c2_list_cell *)0x0)) {
        pcVar2 = get_trip_counter(loop,fn);
        if (anchor->line != 0) {
          g_current_line_abs = fn->line_base + (uint)anchor->line;
          g_cur_line = anchor->line;
        }
        insert_fn = tuple_insert_before;
        pcVar4 = anchor;
        pcVar3 = operand_new_intconst(0x2004,1,0);
        pcVar4 = tuple_new_binary_temp(0x16e,0x2004,pcVar2,pcVar3,insert_fn,pcVar4);
        pcVar4->flags13 = '\x04';
        add_symbol_loop_use(pcVar5,pcVar4);
        pcVar4 = tuple_new(0x15b,0x2004,pcVar2,pcVar4->dst,tuple_insert_before,anchor);
        pcVar4->flags13 = '\x04';
        add_symbol_loop_def(pcVar5,pcVar4);
        anchor->type = 0x2004;
        tuple_replace_src(anchor,anchor->src,pcVar2);
        pcVar3 = operand_new_intconst(0x2004,0,0);
        tuple_replace_src(anchor,anchor->src->next,pcVar3);
        pcVar4 = find_next_use_of_dst(anchor,&local_4);
        *(undefined1 *)&pcVar4->type = 4;
        pcVar5 = cse_find_or_make(0x181,0x2004,anchor->src,anchor->src->next);
        (anchor->u14).expr = pcVar5;
        recompute_loop_liveness(loop,3);
      }
      return;
    }
    if ((((pcVar1->u04).tuple)->flags13 != '\x04') && ((pcVar1->u04).tuple != anchor)) break;
    pcVar1 = pcVar1->next;
  }
  return;
}

