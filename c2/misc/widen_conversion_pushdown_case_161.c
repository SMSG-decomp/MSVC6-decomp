c2_tuple *
widen_conversion_pushdown_case_161
          (uint16_t src_type,c2_tuple *t,uint16_t type,uint16_t size_change,uint16_t wide_type,
          c2_tuple *parent,c2_tuple *result,c2_operand *prev_src)

{
  c2_tuple *inner;
  c2_tuple *operand_conv;
  c2_operand *old_head;
  c2_operand *pcVar1;
  c2_operand *opnd;
  c2_operand *inner_dst;
  c2_operand *next_opnd;
  
  if (((src_type & 0xf000) == 0x2000) && (size_change != 0)) {
    return t;
  }
  if ((short)result != 2) {
    inner = (c2_tuple *)tuple_forward_src_and_free(t,parent);
    inner_dst = inner->dst;
    operand_conv = (c2_tuple *)inner_dst->sym;
    inner->type = wide_type;
    operand_conv = (c2_tuple *)
                   symbol_get_part((c2_symbol *)operand_conv,wide_type,wide_type & 0xfff,0);
    inner_dst->sym = (c2_symbol *)operand_conv;
    if ((inner_dst->kind == '\x01') && ((operand_conv->u14).arg != (void *)0x0)) {
      (inner_dst->u18).reg = (c2_symbol *)operand_conv;
    }
    inner_dst->type = wide_type;
    result = inner;
    if (wide_type != type) {
      if (parent != (c2_tuple *)0x0) {
        prev_src = (c2_operand *)list_find_prev((c2_link *)parent->src,(c2_link *)inner);
        tuple_detach_src((c2_node *)parent,(c2_operand *)inner);
      }
      old_head = operand_new_temp(type);
      result = tuple_new_unary_temp(0x15f,type,old_head,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      tuple_replace_src(result,(((c2_operand *)result)->u18).children,(c2_operand *)inner);
      *(undefined1 *)&((c2_operand *)result)->x12 = 2;
      if (parent != (c2_tuple *)0x0) {
        if (prev_src == (c2_operand *)0x0) {
          old_head = parent->src;
          parent->src = (c2_operand *)result;
          ((c2_operand *)result)->next = old_head;
        }
        else {
          tuple_insert_src_after(parent,prev_src,(c2_operand *)result);
        }
      }
      tuple_unlink_mem_subops(result);
      *(undefined1 *)&((c2_operand *)result)->x12 = 2;
    }
    old_head = inner->src;
    while (old_head != (c2_operand *)0x0) {
      next_opnd = old_head->next;
      if (inner != (c2_tuple *)0x0) {
        prev_src = (c2_operand *)list_find_prev((c2_link *)inner->src,(c2_link *)old_head);
        tuple_detach_src((c2_node *)inner,old_head);
      }
      pcVar1 = operand_new_temp(wide_type);
      pcVar1 = (c2_operand *)
               tuple_new_unary_temp(0x15f,wide_type,pcVar1,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      tuple_replace_src((c2_tuple *)pcVar1,(pcVar1->u18).children,old_head);
      *(undefined1 *)&pcVar1->x12 = 2;
      if (inner != (c2_tuple *)0x0) {
        if (prev_src == (c2_operand *)0x0) {
          opnd = inner->src;
          inner->src = pcVar1;
          pcVar1->next = opnd;
        }
        else {
          tuple_insert_src_after(inner,prev_src,pcVar1);
        }
      }
      tuple_unlink_mem_subops((c2_tuple *)pcVar1);
      *(undefined1 *)&pcVar1->x12 = 2;
      old_head = next_opnd;
    }
    g_simplify_changed = 1;
    t = result;
  }
  return t;
}

