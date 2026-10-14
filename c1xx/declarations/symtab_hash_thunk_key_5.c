int __cdecl symtab_hash_thunk_key_5(int *key)

{
  return ((*(ushort *)(key + 1) & 0x3ffc) >> 2) + key[3] + key[2] + *key;
}

