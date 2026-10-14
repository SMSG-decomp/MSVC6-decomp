c2_live_range * __fastcall requeue_split_pieces(c2_bitset *bs,c2_live_range *head)

{
  uint32_t id;
  c2_live_range *range;
  
  if ((bs->chunks != (c2_bitset_chunk *)0x0) && (id = bitset_iter_next(bs), id != 0xffffffff)) {
    do {
      range = live_range_from_id(id);
      range->flags5 = range->flags5 | 0x20;
      restrict_allowed_registers(range);
      head = insert_live_range_by_priority(range,head);
      id = bitset_iter_next((c2_bitset *)0x0);
    } while (id != 0xffffffff);
    return head;
  }
  return head;
}

