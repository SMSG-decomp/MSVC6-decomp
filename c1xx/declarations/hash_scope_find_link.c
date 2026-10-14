int * __thiscall hash_scope_find_link(void *this,int *entry)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(*(int *)((int)this + 0x14) +
                  (*(uint *)(*entry + 8) & *(uint *)((int)this + 0x18) & 0xffff) * 4);
  piVar2 = (int *)*piVar1;
  if (piVar2 != entry) {
    while( true ) {
      piVar1 = piVar2 + 1;
      piVar2 = (int *)piVar2[1];
      if (piVar2 == (int *)0x0) break;
      if (piVar2 == entry) {
        return piVar1;
      }
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

