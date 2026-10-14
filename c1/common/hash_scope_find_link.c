int * __thiscall hash_scope_find_link(c1_scope_object *hash_scope,int *entry)

{
  int *piVar1;
  void **ppvVar2;
  int *piVar3;
  
  ppvVar2 = (hash_scope->entries).buckets + (*(uint *)(*entry + 8) & hash_scope->mask & 0xffff);
  piVar3 = *ppvVar2;
  if (piVar3 != entry) {
    while( true ) {
      piVar1 = piVar3 + 1;
      piVar3 = (int *)piVar3[1];
      if (piVar3 == (int *)0x0) break;
      if (piVar3 == entry) {
        return piVar1;
      }
    }
    ppvVar2 = (void **)0x0;
  }
  return (int *)ppvVar2;
}

