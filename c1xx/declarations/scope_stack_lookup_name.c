int __thiscall scope_stack_lookup_name(void *stack,void *name,char functions)

{
  char cVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  bool bVar5;
  
  bVar3 = *(byte *)((int)stack + 0x208);
  do {
    piVar2 = *(int **)((int)stack + (uint)bVar3 * 4 + 8);
    cVar1 = (char)piVar2[2];
    if ((cVar1 != '\x01') && (cVar1 != -6)) {
      if (cVar1 == '\0') {
        if (functions != '\0') {
          iVar4 = (**(code **)(*piVar2 + 0x1c))(name);
          goto joined_r0x10493f0c;
        }
      }
      else if (cVar1 == -1) {
        if (functions == '\0') {
          iVar4 = (**(code **)(*piVar2 + 0x1c))(name);
joined_r0x10493f0c:
          if (iVar4 != 0) {
            return iVar4;
          }
        }
      }
      else if ((*(byte *)(piVar2 + 2) != 0) && (*(byte *)(piVar2 + 2) < 0xf9)) {
        iVar4 = (**(code **)(*piVar2 + 0x1c))(name);
        goto joined_r0x10493f0c;
      }
    }
    bVar5 = bVar3 == 0;
    bVar3 = bVar3 - 1;
    if (bVar5) {
      return 0;
    }
  } while( true );
}

