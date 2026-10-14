c1_type * __cdecl type_intern(c1_type *proto)

{
  uint *entry;
  uint *next_free;
  uint **bucket;
  uint *entry_words;
  uint *entry_words_2;
  
  bucket = (uint **)(g_type_hash +
                    ((uint)(&((proto->extra).cls)->kind +
                           (uint)proto->flags + (uint)proto->code + ((uint)proto->base >> 2)) &
                    0x7ff) * 4);
  entry_words = *bucket;
  while( true ) {
    if (entry_words == (uint *)0x0) {
      if (g_type_entry_pool_left < 0x14) {
        pool_reserve((c1xx_pool *)&g_type_entry_pool,0x14);
      }
      entry = g_type_entry_pool;
      g_type_entry_pool_left = g_type_entry_pool_left - 0x14;
      if (g_type_entry_pool == (uint *)0x0) {
        entry = (uint *)0x0;
        g_type_entry_pool = g_type_entry_pool + 5;
      }
      else {
        entry_words_2 = g_type_entry_pool + 1;
        next_free = g_type_entry_pool + 5;
        *g_type_entry_pool = (uint)*bucket;
        g_type_entry_pool = next_free;
        *entry_words_2 = *(uint *)proto;
        entry[2] = (uint)proto->base;
        *(c1_type_extra *)(entry + 3) = proto->extra;
        entry[4] = proto->debug_index;
      }
      *bucket = entry;
      if (g_opt_Zi != '\0') {
        entry[4] = 0;
      }
      return (c1_type *)(entry + 1);
    }
    if ((((proto->base == (c1_type *)entry_words[2]) &&
         ((proto->extra).cls == (c1_symbol *)entry_words[3])) &&
        (proto->code == (ushort)entry_words[1])) &&
       (proto->flags == *(ushort *)((int)entry_words + 6))) break;
    entry_words = (uint *)*entry_words;
  }
  return (c1_type *)(entry_words + 1);
}

