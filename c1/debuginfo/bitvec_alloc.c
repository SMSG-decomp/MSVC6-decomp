int __thiscall bitvec_alloc(fe_bitvec *bitvec,int nbits,fe_arena *a)

{
  uchar *puVar1;
  fe_arena *a_00;
  uchar *puVar2;
  int iVar3;
  uint uVar4;
  uint n;
  
  uVar4 = (nbits >> 3) + 5;
  n = uVar4 & 0xfffffffc;
  if (a == (fe_arena *)0x0) {
    if (bitvec->in_arena == '\x01') {
      a_00 = bitvec->arena;
      puVar1 = a_00->cur;
      puVar2 = puVar1 + n;
      a_00->cur = puVar2;
      if (a_00->end < puVar2) {
        arena_grow(a_00);
      }
      bitvec->bits = puVar1;
    }
    else {
      puVar2 = mem_xmalloc(n);
      bitvec->bits = puVar2;
    }
    bitvec->owns_bits = '\x01';
  }
  else {
    puVar1 = a->cur;
    puVar2 = puVar1 + n;
    a->cur = puVar2;
    if (a->end < puVar2) {
      arena_grow(a);
    }
    bitvec->bits = puVar1;
    bitvec->owns_bits = '\0';
  }
  if (bitvec->bits == (uchar *)0x0) {
    return 0;
  }
  bitvec->iter_bit = 0;
  bitvec->iter_byte = 0;
  bitvec->nbits = nbits;
  bitvec->nbytes = n;
  puVar2 = bitvec->bits;
  for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    puVar2[0] = '\0';
    puVar2[1] = '\0';
    puVar2[2] = '\0';
    puVar2[3] = '\0';
    puVar2 = puVar2 + 4;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = '\0';
    puVar2 = puVar2 + 1;
  }
  return 1;
}

