int __cdecl
class_subobject_special_member_usable(c1_symbol *cls,c1_symbol *sub,c1_u8 *rows,int kind)

{
  c1_u8 *pcVar1;
  c1_class_record *pcVar2;
  int iVar3;
  byte bVar4;
  
  pcVar1 = rows + kind * 7;
  pcVar1[1] = '\x01';
  pcVar2 = (sub->detail).cls;
  bVar4 = (byte)(1 << ((byte)kind & 0x1f));
  if (((pcVar2->implicit_state43 & bVar4) != 0) && ((pcVar2->implicit_state45 & bVar4) == 0)) {
    if ((pcVar2->implicit_state44 & bVar4) == 0) {
      iVar3 = access_is_friend(cls,sub);
      if (iVar3 == 0) goto LAB_10439ef6;
    }
    if (kind == 2) {
      bVar4 = ((sub->detail).cls)->pm_model >> 4 & 3;
    }
    else if (kind == 3) {
      bVar4 = ((sub->detail).cls)->pm_model >> 6;
    }
    else {
      bVar4 = 1;
    }
    bVar4 = pcVar1[6] & bVar4 & 1;
    pcVar1[6] = bVar4;
    if (kind != 2) {
      if (kind != 3) {
        pcVar1[6] = bVar4;
        return 1;
      }
      pcVar1[6] = ((sub->detail).cls)->pm_model >> 6 & 2 | bVar4;
      return 1;
    }
    pcVar1[6] = ((sub->detail).cls)->pm_model >> 4 & 2 | bVar4;
    return 1;
  }
LAB_10439ef6:
  *pcVar1 = '\0';
  return 0;
}

