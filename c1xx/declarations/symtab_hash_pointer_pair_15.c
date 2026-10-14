int __cdecl symtab_hash_pointer_pair_15(ushort *key)

{
  return ((key[2] & 0x3ffc) >> 2) + ((*key & 0x3ffc) >> 2);
}

