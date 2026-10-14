void __fastcall
prune_low_use_live_ranges(c2_function *fn,int reg_class,c2_bitset *set,c2_bitset *dst)

{
  uint32_t id;
  c2_live_range *lr;
  c2_bitset *bs;
  
  bs = (c2_bitset *)0x0;
  id = bitset_iter_next(set);
  if (id != 0xffffffff) {
    do {
      lr = live_range_from_id(id);
      if ((lr->refcount < 2) &&
         ((lr->weight < 1 || (((lr->u38).def != (c2_tuple *)0x0 && (((lr->u38).def)->op != 0x163))))
         )) {
        demote_live_range(fn,lr);
        if (bs == (c2_bitset *)0x0) {
          bs = bitset_new(6);
        }
        bitset_set(bs,id);
      }
      else if (lr->refcount == 2) {
        bs = fold_two_ref_load_range(lr,id,bs);
      }
      id = bitset_iter_next((c2_bitset *)0x0);
    } while (id != 0xffffffff);
    if (bs != (c2_bitset *)0x0) {
      bitset_andnot(set,bs);
      if (dst == (c2_bitset *)0x0) {
        if ((g_ranges_pending_removal != (c2_bitset *)0x0) &&
           (bitset_andnot(g_ranges_pending_removal,bs),
           g_ranges_pending_removal->chunks == (c2_bitset_chunk *)0x0)) {
          bitset_free(g_ranges_pending_removal);
          g_ranges_pending_removal = (c2_bitset *)0x0;
        }
      }
      else {
        bitset_andnot(dst,bs);
      }
      bitset_free(bs);
      recompute_last_use_flags(fn,reg_class);
    }
  }
  return;
}

