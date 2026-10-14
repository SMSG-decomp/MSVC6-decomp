uint __cdecl type_param_list_hash(int *list)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  
  puVar4 = (ushort *)(list + 2);
  uVar3 = *list;
  uVar2 = 0;
  for (uVar5 = uVar3; uVar5 != 0; uVar5 = uVar5 - 1) {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 2;
    uVar3 = uVar3 + ((uVar1 & 0x3ffc) >> 2);
    uVar2 = uVar3;
  }
  return uVar2;
}

