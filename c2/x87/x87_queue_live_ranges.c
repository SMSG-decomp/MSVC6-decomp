c2_live_range * __fastcall x87_queue_live_ranges(c2_bitset *ranges,c2_live_range *queue)

{
  c2_live_range *pcVar1;
  int iVar2;
  c2_block *pcVar3;
  uint32_t id;
  c2_live_range *pcVar4;
  c2_live_range *pcVar5;
  c2_tuple *pcVar6;
  
  if (ranges->chunks != (c2_bitset_chunk *)0x0) {
    id = bitset_iter_next(ranges);
    while (id != 0xffffffff) {
      pcVar4 = live_range_from_id(id);
      pcVar4->flags5 = pcVar4->flags5 & 0xfe;
      if ((pcVar4->u38).def == (c2_tuple *)0x0) {
        pcVar6 = alloc_split_cell();
        pcVar3 = pcVar4->last_block;
        pcVar6->next = (c2_tuple *)0x0;
        (pcVar4->u38).def = pcVar6;
        pcVar6->op = (uint32_t)pcVar3->end;
      }
      if (queue == (c2_live_range *)0x0) {
        (pcVar4->u14).queue_next = (c2_live_range *)0x0;
        pcVar4->queue_prev = (c2_live_range *)0x0;
      }
      else {
        iVar2 = pcVar4->priority;
        if ((queue->priority < iVar2) ||
           ((pcVar1 = queue, iVar2 == queue->priority && (queue->tie <= pcVar4->tie)))) {
          pcVar4->queue_prev = (c2_live_range *)0x0;
          (pcVar4->u14).queue_next = queue;
          queue->queue_prev = pcVar4;
        }
        else {
          do {
            pcVar5 = pcVar1;
            if ((pcVar5->priority <= iVar2) &&
               ((iVar2 != pcVar5->priority || (pcVar5->tie <= pcVar4->tie)))) break;
            pcVar1 = (pcVar5->u14).queue_next;
          } while ((pcVar5->u14).queue_next != (c2_live_range *)0x0);
          if ((iVar2 < pcVar5->priority) ||
             ((pcVar5->priority == iVar2 && (pcVar4->tie < pcVar5->tie)))) {
            (pcVar5->u14).queue_next = pcVar4;
            pcVar4->queue_prev = pcVar5;
            (pcVar4->u14).queue_next = (c2_live_range *)0x0;
            pcVar4 = queue;
          }
          else {
            pcVar1 = pcVar5->queue_prev;
            (pcVar4->u14).queue_next = pcVar5;
            pcVar4->queue_prev = pcVar1;
            pcVar1 = pcVar5->queue_prev;
            pcVar5->queue_prev = pcVar4;
            (pcVar1->u14).queue_next = pcVar4;
            pcVar4 = queue;
          }
        }
      }
      id = bitset_iter_next((c2_bitset *)0x0);
      queue = pcVar4;
    }
  }
  bitset_clear_all(ranges);
  return queue;
}

