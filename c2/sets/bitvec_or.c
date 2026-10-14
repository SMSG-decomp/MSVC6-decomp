void __fastcall bitvec_or(c2_bitvec *v,c2_bitvec *vec)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = v->words;
  uVar2 = (vec->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar2 != 0) {
    iVar3 = (int)vec->words - (int)puVar1;
    do {
      *puVar1 = *puVar1 | *(uint *)(iVar3 + (int)puVar1);
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

