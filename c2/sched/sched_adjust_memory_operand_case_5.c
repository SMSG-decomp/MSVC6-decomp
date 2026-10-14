int sched_adjust_memory_operand_case_5
              (c2_tuple *producer,c2_operand *mem,c2_tuple *consumer,c2_tuple *producer_tuple,
              c2_sched_node *from,c2_sched_edge *edge)

{
  uint8_t *puVar1;
  byte bVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  c2_operand *pcVar6;
  
  for (pcVar3 = producer->src; (pcVar3 != (c2_operand *)0x0 && (pcVar3->kind != '\x05'));
      pcVar3 = pcVar3->next) {
  }
  pcVar6 = mem->base;
  if (pcVar6 != (c2_operand *)0x0) {
    pcVar6->flags = pcVar6->flags & 0xdf;
    tuple_detach_src((c2_node *)consumer,pcVar6);
    node_free((c2_node *)mem->base);
    mem->base = (c2_operand *)0x0;
  }
  pcVar6 = mem->index;
  if (pcVar6 != (c2_operand *)0x0) {
    pcVar6->flags = pcVar6->flags & 0xdf;
    tuple_detach_src((c2_node *)consumer,pcVar6);
    node_free((c2_node *)mem->index);
    mem->index = (c2_operand *)0x0;
  }
  if (pcVar3->base != (c2_operand *)0x0) {
    pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar3->base);
    mem->base = pcVar6;
    tuple_append_src(consumer,pcVar6);
    puVar1 = &mem->base->flags;
    *puVar1 = *puVar1 | 0x10;
  }
  if (pcVar3->index != (c2_operand *)0x0) {
    pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar3->index);
    mem->index = pcVar6;
    tuple_append_src(consumer,pcVar6);
    puVar1 = &mem->index->flags;
    *puVar1 = *puVar1 | 0x10;
  }
  bVar2 = pcVar3->flags;
  pcVar4 = pcVar3->base_sym;
  mem->op = pcVar3->op;
  iVar5 = pcVar3->disp;
  mem->base_sym = pcVar4;
  mem->flags = (bVar2 ^ mem->flags) & 0xf ^ mem->flags;
  mem->disp = mem->disp + iVar5;
  sched_remove_edge(edge);
  if ((edge->soft & 0x20) == 0) {
    if (from->nsucc == 0) {
      sched_link_to_next_barrier(from);
    }
  }
  else {
    sched_retire_node(from);
  }
  bVar2 = producer_tuple->flags;
  consumer->flags = consumer->flags & 0xfb;
  producer_tuple->flags = bVar2 & 0xfb;
  return 1;
}

