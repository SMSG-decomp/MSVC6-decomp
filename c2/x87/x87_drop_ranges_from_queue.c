c2_live_range * __fastcall x87_drop_ranges_from_queue(c2_live_range *queue,c2_bitset *ids)

{
  c2_live_range *pcVar1;
  uint32_t id;
  c2_live_range *pcVar2;
  
  id = bitset_iter_next(ids);
  if (id == 0xffffffff) {
    return queue;
  }
  do {
    pcVar2 = live_range_from_id(id);
    pcVar2->flags5 = pcVar2->flags5 | 2;
    free_split_cell_list(pcVar2->prefs);
    free_split_cell_list((pcVar2->u38).def);
    if (pcVar2 == queue) {
      queue = (queue->u14).queue_next;
      if (queue != (c2_live_range *)0x0) {
        queue->queue_prev = (c2_live_range *)0x0;
      }
    }
    else {
      pcVar1 = pcVar2->queue_prev;
      pcVar2 = (pcVar2->u14).queue_next;
      (pcVar1->u14).queue_next = pcVar2;
      if (pcVar2 != (c2_live_range *)0x0) {
        pcVar2->queue_prev = pcVar1;
      }
    }
    id = bitset_iter_next((c2_bitset *)0x0);
  } while (id != 0xffffffff);
  return queue;
}

