uint32_t __fastcall symbol_in_set_or_flag(c2_symbol *s,c2_bitset *set)

{
  c2_bitset_chunk *pcVar1;
  uint uVar2;
  
  if (s->def != (c2_tuple *)0x0) {
    return (uint)(s->u30).globopt.live;
  }
  pcVar1 = set->chunks;
  uVar2 = s->id & 0xffffffe0;
  while( true ) {
    if (pcVar1 == (c2_bitset_chunk *)0x0) {
      return 0;
    }
    if (uVar2 <= pcVar1->base) break;
    pcVar1 = pcVar1->next;
  }
  if (pcVar1->base != uVar2) {
    return 0;
  }
  if (pcVar1 == (c2_bitset_chunk *)0x0) {
    return 0;
  }
  return 1 << ((byte)s->id & 0x1f) & pcVar1->bits;
}

