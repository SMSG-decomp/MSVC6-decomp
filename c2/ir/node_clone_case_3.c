c2_node * node_clone_case_3(c2_tuple *node,uint8_t kind,c2_tuple *clone,c2_tuple *clone_slot,
                           uint32_t subop_seen)

{
  byte bVar1;
  uint32_t uVar2;
  c2_operand *pcVar3;
  bool bVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  
  uVar2 = node->op;
  if (kind == '\x14') {
    if (uVar2 == 0x1a0) {
      cxx_eh_copy_object_record((c2_node *)node,(c2_node *)clone);
    }
    else if ((uVar2 == 0x1ab) && ((node->u20).tuples != (c2_tuple *)0x0)) {
      pcVar6 = clone_tuple_list((node->u20).tuples);
      (clone->u20).tuples = pcVar6;
    }
  }
  else if (uVar2 == 0x188) {
    seh_register_finally_call_clone(node,clone);
  }
  pcVar3 = node->src;
  bVar4 = false;
  if (pcVar3 != (c2_operand *)0x0) {
    pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar3);
    bVar1 = pcVar5->kind;
    clone_slot->src = pcVar5;
    if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
      pcVar5->flags = pcVar5->flags | 0x10;
    }
    for (pcVar3 = pcVar3->next; clone = clone_slot, pcVar3 != (c2_operand *)0x0;
        pcVar3 = pcVar3->next) {
      if (((1 << (pcVar3->kind & 0x1f) & 0xffeU) == 0) || ((pcVar3->flags & 0x20) == 0)) {
        pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar3);
        pcVar5->next = pcVar7;
        pcVar5 = pcVar7;
        if ((1 << (pcVar7->kind & 0x1f) & 0xffeU) != 0) {
          pcVar7->flags = pcVar7->flags | 0x10;
        }
      }
      else {
        bVar4 = true;
      }
    }
  }
  pcVar3 = node->dst;
  if (pcVar3 != (c2_operand *)0x0) {
    pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar3);
    clone_slot->dst = pcVar5;
    if ((1 << (pcVar5->kind & 0x1f) & 0xffeU) != 0) {
      pcVar5->flags = pcVar5->flags | 0x10;
    }
    for (pcVar3 = pcVar3->next; clone = clone_slot, pcVar3 != (c2_operand *)0x0;
        pcVar3 = pcVar3->next) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar3);
      pcVar5->next = pcVar7;
      if ((1 << (pcVar7->kind & 0x1f) & 0xffeU) != 0) {
        pcVar7->flags = pcVar7->flags | 0x10;
      }
      pcVar5 = pcVar7;
    }
  }
  if (bVar4) {
    tuple_link_mem_subops(clone);
  }
  clone->prev = (c2_tuple *)0x0;
  return (c2_node *)clone;
}

