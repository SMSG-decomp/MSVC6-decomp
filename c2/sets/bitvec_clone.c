c2_bitvec * __fastcall bitvec_clone(c2_bitvec *v)

{
  c2_bitvec *pcVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = v->nbits & 0xffffff;
  pcVar1 = bitvec_new((uint)v->arena,uVar4);
  puVar2 = pcVar1->words;
  uVar4 = uVar4 + 0x1f >> 5;
  if (uVar4 != 0) {
    iVar3 = (int)v->words - (int)puVar2;
    do {
      *puVar2 = *puVar2 | *(uint *)(iVar3 + (int)puVar2);
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return pcVar1;
}

