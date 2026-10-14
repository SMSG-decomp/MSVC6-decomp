uint __cdecl symtab_hash_name(int name)

{
  return *(uint *)(name + 8) & 0xffff;
}

