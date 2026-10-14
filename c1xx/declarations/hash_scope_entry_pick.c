int __cdecl hash_scope_entry_pick(int entry)

{
  int iVar1;
  
  if ((*(byte *)(entry + -6) & 0x10) == 0) {
    iVar1 = *(int *)(entry + 4);
  }
  else {
    iVar1 = entry;
    entry = *(int *)(entry + 4);
  }
  if (((byte)g_compile_flags_c4 & 0x10) == 0) {
    iVar1 = entry;
  }
  return iVar1;
}

