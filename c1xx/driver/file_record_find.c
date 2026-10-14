int * __thiscall file_record_find(void *scope,int name)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)scope + 0x22c);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*piVar1 == name) break;
    piVar1 = (int *)piVar1[5];
  }
  return piVar1;
}

