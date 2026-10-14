int __cdecl mem_chain_read(int *cursor,void *dest,uint n)

{
  int iVar1;
  char *src;
  uint uVar2;
  int iVar3;
  int local_4;
  
  iVar3 = cursor[2];
  local_4 = 0;
  if (iVar3 == 0) {
    return 0;
  }
  do {
    src = (char *)cursor[1];
    iVar1 = *cursor;
    if (*(int *)(iVar3 + 0x7fc) == 0) {
      if (0x7f8U - iVar1 < n) {
        *cursor = 0;
        n = n - (0x7f8U - iVar1);
        iVar3 = *(int *)(cursor[2] + 0x7f8);
        cursor[2] = iVar3;
        cursor[1] = iVar3;
        uVar2 = 0x7f8U - iVar1;
      }
      else {
        *cursor = iVar1 + n;
        iVar3 = 0;
        cursor[1] = (int)(src + n);
        uVar2 = n;
      }
    }
    else {
      uVar2 = *(int *)(iVar3 + 0x7fc) - iVar1;
      if (n <= uVar2) {
        uVar2 = n;
      }
      *cursor = iVar1 + uVar2;
      cursor[1] = (int)(src + uVar2);
      iVar3 = 0;
    }
    local_4 = local_4 + uVar2;
    if (0 < (int)uVar2) {
      do {
        *(char *)dest = *src;
        dest = (void *)((int)dest + 1);
        src = src + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
  } while (iVar3 != 0);
  return local_4;
}

