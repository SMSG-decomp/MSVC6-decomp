void __cdecl
class_declare_implicit_member_by_state
          (c1_symbol *cls,c1_u8 *states,int kind,int warning,char allowed)

{
  byte bVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  c1_class_record *pcVar4;
  
  pcVar2 = states + kind * 7;
  bVar1 = (byte)kind;
  if (pcVar2[2] != '\0') {
    ((cls->detail).cls)->implicit_state43 =
         ((cls->detail).cls)->implicit_state43 | pcVar2[3] << (bVar1 & 0x1f);
    ((cls->detail).cls)->implicit_state44 =
         ((cls->detail).cls)->implicit_state44 | pcVar2[4] << (bVar1 & 0x1f);
    ((cls->detail).cls)->implicit_state45 =
         ((cls->detail).cls)->implicit_state45 | pcVar2[5] << (bVar1 & 0x1f);
    return;
  }
  if (allowed == '\0') {
    return;
  }
  if (pcVar2[1] != '\0') {
    if (*pcVar2 == '\0') {
      diag_warning(4,warning,cls);
      return;
    }
    bVar1 = '\x01' << (bVar1 & 0x1f);
    pcVar2 = &((cls->detail).cls)->implicit_state42;
    *pcVar2 = *pcVar2 | bVar1;
    pcVar2 = &((cls->detail).cls)->implicit_state43;
    *pcVar2 = *pcVar2 | bVar1;
    pcVar2 = &((cls->detail).cls)->implicit_state44;
    *pcVar2 = *pcVar2 | bVar1;
    if (kind == 2) {
      pcVar4 = (cls->detail).cls;
      bVar3 = (states[0x14] & 3) << 4;
      bVar1 = pcVar4->pm_model & 0xcf;
    }
    else {
      if (kind != 3) goto LAB_104362f5;
      pcVar4 = (cls->detail).cls;
      bVar3 = states[0x1b] << 6;
      bVar1 = pcVar4->pm_model & 0x3f;
    }
    pcVar4->pm_model = bVar3 | bVar1;
LAB_104362f5:
    class_declare_implicit_member(cls,kind,'\x01','\0');
    return;
  }
  bVar1 = '\x01' << (bVar1 & 0x1f);
  ((cls->detail).cls)->implicit_state41 = ((cls->detail).cls)->implicit_state41 | bVar1;
  ((cls->detail).cls)->implicit_state44 = ((cls->detail).cls)->implicit_state44 | bVar1;
  if (kind == 2) {
    pcVar4 = (cls->detail).cls;
    bVar1 = pcVar4->pm_model & 0xdf | 0x10;
  }
  else {
    if (kind != 3) goto LAB_10436262;
    pcVar4 = (cls->detail).cls;
    bVar1 = pcVar4->pm_model & 0x3f | 0x40;
  }
  pcVar4->pm_model = bVar1;
LAB_10436262:
  class_declare_implicit_member(cls,kind,kind == 3,'\x01');
  return;
}

