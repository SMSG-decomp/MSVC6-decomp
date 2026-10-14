void __fastcall intersect_live_with_avail(c2_block *b)

{
  for (; b != (c2_block *)0x0; b = b->next) {
    bitset_and(b->live_in,(b->avail_in).set);
    bitset_and(b->live_out,(b->avail_out).set);
  }
  return;
}

