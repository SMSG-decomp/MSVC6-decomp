void __fastcall arena_reset_ptr(fe_arena *a)

{
  uint uVar1;
  uint uVar2;
  uchar *puVar3;
  
  uVar1 = (int)a->cur - (int)a->base;
  puVar3 = a->base;
  for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar3[0] = '\0';
    puVar3[1] = '\0';
    puVar3[2] = '\0';
    puVar3[3] = '\0';
    puVar3 = puVar3 + 4;
  }
  for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = '\0';
    puVar3 = puVar3 + 1;
  }
  a->cur = a->base;
  return;
}

