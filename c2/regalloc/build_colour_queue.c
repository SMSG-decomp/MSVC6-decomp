c2_bitset * __fastcall build_colour_queue(c2_function *fn,int reg_class,c2_bitset *empty_set)

{
  byte bVar1;
  c2_live_range *range;
  c2_bitset *bs;
  c2_bitset *regs;
  c2_live_range *head;
  c2_live_range **bucket;
  
  head = (c2_live_range *)0x0;
  bs = bitset_clone(g_class_allowed_sets[reg_class]);
  if (g_ebp_allocatable == 0) {
    bitset_clear(bs,6);
  }
  bucket = g_live_range_hash;
  do {
    for (range = *bucket; range != (c2_live_range *)0x0; range = range->hash_next) {
      if (g_type_class[range->sym->type >> 0xc] == reg_class) {
        restrict_allowed_registers(range);
        if (range->allowed->chunks == (c2_bitset_chunk *)0x0) {
          bVar1 = range->flags5;
          range->flags5 = bVar1 | 2;
          if (empty_set == (c2_bitset *)0x0) {
            empty_set = bitset_new(6);
          }
          bitset_set(empty_set,range->id);
          regs = g_byte_register_set;
          if ((bVar1 & 0x80) == 0) {
            regs = bs;
          }
          place_split_points_for_range(range,regs);
        }
        head = insert_live_range_by_priority(range,head);
      }
    }
    bucket = bucket + 1;
  } while ((int)bucket < 0x1079e88c);
  bitset_free(bs);
  g_colour_queue = head;
  return empty_set;
}

