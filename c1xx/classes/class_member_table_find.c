int __thiscall class_member_table_find(void *table,uint name)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  uint **ranges;
  
  ranges = *(uint ***)((int)table + 4);
  iVar6 = 0;
  iVar5 = *(int *)table + -1;
  if ((name <= *ranges[iVar5]) && (**ranges <= name)) {
    do {
      uVar3 = (uint)(iVar5 + iVar6) >> 1;
      uVar1 = *ranges[uVar3];
      if (name < uVar1) {
        iVar5 = uVar3 - 1;
      }
      else {
        iVar6 = uVar3 + 1;
      }
      if (uVar1 == name) goto LAB_1041143b;
    } while (iVar6 <= iVar5);
    if (uVar1 == name) {
LAB_1041143b:
      puVar2 = ranges[uVar3];
      if ((*(byte *)((int)puVar2 + -6) & 0x40) == 0) {
        return (int)puVar2;
      }
      pvVar4 = sym_hiding_partner(puVar2 + -2);
      return (int)pvVar4 + 8;
    }
  }
  return 0;
}

