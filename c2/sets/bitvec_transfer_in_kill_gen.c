void __fastcall
bitvec_transfer_in_kill_gen
          (c2_bitvec *out,c2_bitvec *gen,c2_bitvec *in,c2_bitvec *kill,int *changed)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar1 = kill->words;
  uVar2 = (in->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar2 != 0) {
    iVar5 = (int)in->words - (int)puVar1;
    iVar6 = (int)gen->words - (int)puVar1;
    iVar4 = (int)out->words - (int)puVar1;
    do {
      uVar3 = *(uint *)(iVar5 + (int)puVar1) & ~*puVar1 | *(uint *)(iVar6 + (int)puVar1);
      if (uVar3 != *(uint *)(iVar4 + (int)puVar1)) {
        *changed = 1;
      }
      *(uint *)(iVar4 + (int)puVar1) = uVar3;
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

