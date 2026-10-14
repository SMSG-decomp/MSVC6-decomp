uint __cdecl symtab_hash_pointer_2(uint key)

{
  return key >> 2 & 0xfff;
}

