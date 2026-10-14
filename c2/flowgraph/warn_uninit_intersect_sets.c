void __fastcall warn_uninit_intersect_sets(c2_block *b)

{
  for (; b != (c2_block *)0x0; b = b->next) {
    bitset_and(b->live_in,(b->avail_in).set);
    bitset_and(b->live_out,(b->avail_out).set);
  }
  return;
}

