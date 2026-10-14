int __thiscall iset_remove(ISet *set,uint n)

{
  uint *puVar1;
  
  if (n < (set->rgw).itMac << 5) {
    puVar1 = (set->rgw).rgt + (n >> 5);
    *puVar1 = *puVar1 & ~(1 << ((byte)n & 0x1f));
  }
  return 1;
}

