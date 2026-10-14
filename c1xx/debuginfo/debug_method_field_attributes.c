uint __cdecl debug_method_field_attributes(int method,ushort *attr,uint *vtable_offset)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  ushort uVar5;
  
  *attr = (ushort)g_cv_zero_attributes;
  uVar3 = (ushort)g_cv_zero_attributes;
  bVar4 = *(byte *)(method + 2) & 3;
  *attr = (ushort)bVar4 | uVar3 & 0xfffc;
  uVar2 = (ushort)bVar4;
  uVar5 = (*(byte *)(method + 3) & 1) << 8;
  *attr = uVar5 | uVar2 | uVar3 & 0xfefc;
  if ((*(byte *)(method + 0x21) & 2) == 0) {
    *attr = ((-(ushort)((*(byte *)(method + 0x20) & 7) != 3) & 0xfffe) + 2 & 7) << 2 |
            uVar5 | uVar2 | uVar3 & 0xfee0;
    return 0;
  }
  bVar4 = *(byte *)(method + 0x34);
  if ((bVar4 & 2) == 0) {
    if ((bVar4 & 4) == 0) {
      uVar3 = uVar5 | uVar2 | uVar3 & 0xfef0 | 0x10;
    }
    else {
      uVar3 = uVar5 | uVar2 | uVar3 & 0xfef8 | 0x18;
    }
    *attr = uVar3;
    uVar1 = *(uint *)(method + 0x24);
    *vtable_offset = uVar1;
    return CONCAT22((short)(uVar1 >> 0x10),4);
  }
  if ((bVar4 & 4) == 0) {
    *attr = uVar5 | uVar2 | uVar3 & 0xfee4 | 4;
    return 0;
  }
  *attr = uVar5 | uVar2 | uVar3 & 0xfef4 | 0x14;
  return 0;
}

