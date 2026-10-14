int __fastcall init_record_is_zero(c2_init *rec)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  switch((rec->u08).data.value_kind) {
  case 1:
  case 2:
  case 3:
    switch((rec->u08).data.size) {
    case 1:
      return (uint)(*(char *)((int)&rec->u08 + 4) == '\0');
    case 2:
      return (uint)(*(short *)((int)&rec->u08 + 4) == 0);
    case 4:
      return (uint)((rec->u08).header.offset == 0);
    case 8:
      if (((rec->u08).header.offset == 0) && ((rec->u08).header.sym_id == 0)) {
        return 1;
      }
    }
    break;
  case 5:
    bVar3 = 0;
    uVar2 = (uint)(rec->u08).data.size;
    iVar1 = 0;
    if (uVar2 != 0) {
      do {
        bVar3 = bVar3 | *(byte *)((int)&rec->u08 + iVar1 + 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)uVar2);
    }
    return (uint)(bVar3 == 0);
  case 6:
    bVar3 = 0;
    uVar2 = (uint)(rec->u08).data.size;
    iVar1 = 0;
    if (uVar2 != 0) {
      do {
        bVar3 = bVar3 | *(byte *)((rec->u08).header.offset + iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)uVar2);
    }
    return (uint)(bVar3 == 0);
  }
  return 0;
}

