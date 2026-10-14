c2_bitset * __fastcall
handle_unprofitable_live_range(c2_live_range *lr,c2_function *fn,int reg_class)

{
  uint8_t uVar1;
  c2_live_range *pcVar2;
  byte bVar3;
  int iVar4;
  c2_bitset *bs;
  
  if (((lr->flags6 & 1) == 0) && (iVar4 = force_best_preference(lr), iVar4 != 0)) {
    (lr->u14).queue_next = g_colour_queue;
    if (g_colour_queue != (c2_live_range *)0x0) {
      g_colour_queue->queue_prev = lr;
    }
    g_colour_queue = lr;
    return (c2_bitset *)0x0;
  }
  pcVar2 = g_colour_queue;
  if (((lr->flags5 & 0x40) == 0) && (g_colour_queue != (c2_live_range *)0x0)) {
    lr->flags5 = lr->flags5 | 0x40;
    g_colour_queue = defer_live_range(pcVar2,lr);
    return (c2_bitset *)0x0;
  }
  bVar3 = lr->flags6 & 1;
  if ((bVar3 == 0) && ((lr->first_block == lr->last_block || (lr->flags7 == '\0')))) {
    demote_live_range(fn,lr);
    recompute_last_use_flags(fn,reg_class);
    return (c2_bitset *)0x0;
  }
  if (bVar3 == 0) {
    split_range_at_block_entries(lr);
  }
  else {
    split_constant_range_at_blocks(lr);
  }
  (lr->u14).queue_next = g_colour_queue;
  if (g_colour_queue != (c2_live_range *)0x0) {
    g_colour_queue->queue_prev = lr;
  }
  g_colour_queue = lr;
  bs = bitset_new(6);
  bitset_set(bs,lr->id);
  lr->flags5 = lr->flags5 | 2;
  uVar1 = lr->sym->cls;
  for (pcVar2 = (lr->u14).queue_next; pcVar2 != (c2_live_range *)0x0;
      pcVar2 = (pcVar2->u14).queue_next) {
    if (((pcVar2->weight < 1) &&
        (((bVar3 = pcVar2->flags6 & 1, bVar3 != 0 ||
          ((pcVar2->first_block != pcVar2->last_block && (pcVar2->flags7 != '\0')))) &&
         ((uVar1 == '\r') == (pcVar2->sym->cls == '\r'))))) && ((pcVar2->flags5 & 0x40) != 0)) {
      if (bVar3 == 0) {
        split_range_at_block_entries(pcVar2);
      }
      else {
        split_constant_range_at_blocks(pcVar2);
      }
      bitset_set(bs,pcVar2->id);
      pcVar2->flags5 = pcVar2->flags5 | 2;
    }
  }
  return bs;
}

