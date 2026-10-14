void * __fastcall vector_push_12(int *vector)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  
  uVar1 = vector[2];
  if (uVar1 <= (uint)vector[1]) {
    pvVar3 = arena_alloc_copy_bytes(g_arenas,(void *)*vector,uVar1 * 0xc,uVar1 * 0x18);
    *vector = (int)pvVar3;
    vector[2] = vector[2] << 1;
  }
  iVar2 = vector[1];
  vector[1] = iVar2 + 1;
  return (void *)(*vector + iVar2 * 0xc);
}

