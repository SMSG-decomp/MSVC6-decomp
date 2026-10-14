int * __thiscall sym_list_find_tag(void *scope,int name)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)scope + 4);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*piVar1 == name) && ((*(byte *)(piVar1 + -2) & 0x1f) == 4)) break;
    piVar1 = (int *)piVar1[1];
  }
  return piVar1 + -2;
}

