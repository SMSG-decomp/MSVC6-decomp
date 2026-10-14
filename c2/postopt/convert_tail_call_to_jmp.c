void __fastcall convert_tail_call_to_jmp(c2_tuple *call)

{
  uint8_t uVar1;
  c2_tuple *t;
  c2_operand *pcVar2;
  c2_tuple *first;
  
  if (((call->u24).call.conv == '\x04') && ((call->u20).cond_cells == (c2_cond_cell *)0x0)) {
    t = call->next;
    first = (c2_tuple *)0x0;
    uVar1 = t->kind;
    while (uVar1 != '\x0f') {
      if ((t->flags & 1) != 0) {
        if (t->op != 0xb9) {
          return;
        }
        if (first == (c2_tuple *)0x0) {
          first = t;
        }
        pcVar2 = find_src_overlapping_reg(call,(t->dst->u18).reg);
        if (pcVar2 != (c2_operand *)0x0) {
          return;
        }
        pcVar2 = find_dst_clobbering_reg(call,(t->dst->u18).reg);
        if (pcVar2 != (c2_operand *)0x0) {
          return;
        }
      }
      t = t->next;
      uVar1 = t->kind;
    }
    pcVar2 = t->src;
    if (((pcVar2 != (c2_operand *)0x0) && (pcVar2->kind == '\a')) &&
       ((pcVar2->u18).reg == (c2_symbol *)0x0 && pcVar2->tag == 0)) {
      if (first != (c2_tuple *)0x0) {
        tuple_move_range(call,first,t->prev);
      }
      tuple_unlink_free(t);
      tuple_new_branch(0x10,'\0',(c2_node *)call->src,(c2_operand *)0x0,(c2_tuple *)0x0,
                       tuple_insert_before,call);
      tuple_unlink_free(call);
    }
  }
  return;
}

