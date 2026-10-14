c2_operand * __fastcall add_call_clobbers(c2_tuple *call)

{
  c2_operand *pcVar1;
  c2_operand *node;
  c2_operand *pcVar2;
  
  add_call_clobber_set(call);
  node = operand_new_hardreg(5,0x1004);
  if ((1 << (node->kind & 0x1f) & 0xffeU) != 0) {
    if ((node->flags & 0x10) != 0) {
      node = (c2_operand *)node_clone((c2_node *)node);
    }
    node->flags = node->flags | 0x10;
  }
  pcVar1 = call->src;
  if (call->src != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2->next;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar2 != (c2_operand *)0x0) {
      pcVar2->next = node;
      goto LAB_107029a6;
    }
  }
  call->src = node;
LAB_107029a6:
  if (((1 << (node->kind & 0x1f) & 0x60U) != 0) && ((node->flags11 & 0x20) == 0)) {
    pcVar1 = node->base;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      tuple_append_src(call,pcVar1);
    }
    pcVar1 = node->index;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      tuple_append_src(call,pcVar1);
    }
  }
  return node;
}

