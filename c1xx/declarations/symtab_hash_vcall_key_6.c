int __cdecl symtab_hash_vcall_key_6(int key)

{
  return (uint)*(ushort *)(key + 8) + *(int *)(key + 4);
}

