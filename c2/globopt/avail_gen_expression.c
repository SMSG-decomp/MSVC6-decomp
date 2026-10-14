void __fastcall avail_gen_expression(c2_symbol *e)

{
  uint uVar1;
  c2_bitset *pcVar2;
  c2_bitset_chunk *pcVar3;
  uint uVar4;
  
  if (g_hoisting_in_loop != 0) {
    return;
  }
  uVar1 = e->id;
  pcVar3 = g_cur_avail_set->chunks;
  uVar4 = uVar1 & 0xffffffe0;
  pcVar2 = g_cur_avail_set;
  do {
    if (pcVar3 == (c2_bitset_chunk *)0x0) {
LAB_107018d6:
      pcVar3 = bitset_chunk_alloc(g_cur_avail_set);
      pcVar3->base = uVar4;
      pcVar3->next = pcVar2->chunks;
      pcVar2->chunks = pcVar3;
LAB_10701914:
      pcVar3->bits = pcVar3->bits | 1 << ((byte)uVar1 & 0x1f);
      return;
    }
    if (uVar4 <= pcVar3->base) {
      if (pcVar3->base == uVar4) goto LAB_10701914;
      goto LAB_107018d6;
    }
    pcVar2 = (c2_bitset *)&pcVar3->next;
    pcVar3 = pcVar3->next;
  } while( true );
}

