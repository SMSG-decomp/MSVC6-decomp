uint __cdecl symtab_hash_pointer_7(uint key)

{
  return key >> 2 & 0xfff;
}

