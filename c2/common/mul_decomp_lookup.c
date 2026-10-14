c2_mul_decomp * __fastcall mul_decomp_lookup(int32_t value)

{
  c2_mul_decomp *fresh;
  int bucket;
  c2_mul_decomp *rec;
  
  bucket = ((value ^ value >> 0x1f) - (value >> 0x1f)) % 0x1ff;
  rec = g_mul_decomp_hash[bucket];
  do {
    if (rec == (c2_mul_decomp *)0x0) {
LAB_10719cdf:
      fresh = arena_alloc(1,0x14);
      rec = g_mul_decomp_hash[bucket];
      fresh->value = value;
      fresh->from = (c2_mul_decomp *)0x0;
      fresh->cost = 500;
      fresh->hash_next = rec;
      g_mul_decomp_hash[bucket] = fresh;
      return fresh;
    }
    if (rec->value == value) {
      if (rec != (c2_mul_decomp *)0x0) {
        return rec;
      }
      goto LAB_10719cdf;
    }
    rec = rec->hash_next;
  } while( true );
}

