int __thiscall iset_contains(c1xx_pdb_iset *set,uint bit)

{
  if ((bit < set->count << 5) && ((set->data[bit >> 5] & 1 << ((byte)bit & 0x1f)) != 0)) {
    return 1;
  }
  return 0;
}

