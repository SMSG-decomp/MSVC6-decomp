int __thiscall iset_remove(c1xx_pdb_array *set,uint n)

{
  if (n < set->count << 5) {
    set->data[n >> 5] = set->data[n >> 5] & ~(1 << ((byte)n & 0x1f));
  }
  return 1;
}

