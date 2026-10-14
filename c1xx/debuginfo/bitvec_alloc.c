int __thiscall bitvec_alloc(c1xx_bitvec *bv,int nbits,c1_arena *a)

{
  c1_u8 *pcVar1;
  c1_arena *a_00;
  c1_u8 *pcVar2;
  int iVar3;
  uint uVar4;
  uint n;
  
  uVar4 = (nbits >> 3) + 5;
  n = uVar4 & 0xfffffffc;
  if (a == (c1_arena *)0x0) {
    if (bv->in_arena == '\x01') {
      a_00 = bv->arena;
      pcVar1 = a_00->cur;
      pcVar2 = pcVar1 + n;
      a_00->cur = pcVar2;
      if (a_00->end < pcVar2) {
        arena_grow(a_00);
      }
      bv->bits = pcVar1;
    }
    else {
      pcVar2 = mem_xmalloc(n);
      bv->bits = pcVar2;
    }
    bv->owns_bits = '\x01';
  }
  else {
    pcVar1 = a->cur;
    pcVar2 = pcVar1 + n;
    a->cur = pcVar2;
    if (a->end < pcVar2) {
      arena_grow(a);
    }
    bv->bits = pcVar1;
    bv->owns_bits = '\0';
  }
  if (bv->bits == (c1_u8 *)0x0) {
    return 0;
  }
  bv->iter_bit = 0;
  bv->iter_byte = 0;
  bv->nbits = nbits;
  bv->nbytes = n;
  pcVar2 = bv->bits;
  for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar2 = '\0';
    pcVar2 = pcVar2 + 1;
  }
  return 1;
}

