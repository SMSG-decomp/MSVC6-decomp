uint __cdecl arena_scaled_reserve_size(c1_arena_desc *descriptor)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = descriptor->granule;
  iVar2 = _ftol();
  uVar3 = (uVar1 - iVar2) - 1 & ~(uVar1 - 1);
  if (uVar3 == 0) {
    uVar3 = uVar1;
  }
  return uVar3;
}

