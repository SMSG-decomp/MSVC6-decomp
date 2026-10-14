int __fastcall bitset_equal(c2_bitset *a,c2_bitset *b)

{
  c2_bitset_chunk *pcVar1;
  c2_bitset_chunk *pcVar2;
  
  pcVar1 = a->chunks;
  pcVar2 = b->chunks;
  while( true ) {
    if (pcVar1 == (c2_bitset_chunk *)0x0) {
      return (uint)(pcVar2 == (c2_bitset_chunk *)0x0);
    }
    if (((pcVar2 == (c2_bitset_chunk *)0x0) || (pcVar1->base != pcVar2->base)) ||
       (pcVar1->bits != pcVar2->bits)) break;
    pcVar1 = pcVar1->next;
    pcVar2 = pcVar2->next;
  }
  return 0;
}

