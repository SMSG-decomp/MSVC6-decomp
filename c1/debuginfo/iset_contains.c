int __thiscall iset_contains(ISet *set,uint n)

{
  if ((n < (set->rgw).itMac << 5) && (((set->rgw).rgt[n >> 5] & 1 << ((byte)n & 0x1f)) != 0)) {
    return 1;
  }
  return 0;
}

