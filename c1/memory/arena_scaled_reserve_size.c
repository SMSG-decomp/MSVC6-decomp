uint __cdecl arena_scaled_reserve_size(void *descriptor)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)((int)descriptor + 8);
  iVar2 = _ftol();
  uVar3 = (uVar1 - iVar2) - 1 & ~(uVar1 - 1);
  if (uVar3 == 0) {
    uVar3 = uVar1;
  }
  return uVar3;
}

