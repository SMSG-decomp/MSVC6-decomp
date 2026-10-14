uint16_t __fastcall pdb_il_module_version(uint32_t key,int mod)

{
  int iVar1;
  uint32_t uStack_4;
  uint16_t il_version;
  
  uStack_4 = key;
  iVar1 = ILModGetILVer(g_pdb_il_modules[mod],key,&il_version);
  if (iVar1 == 0) {
    fatal_error(300,g_pdb_name);
  }
  return il_version;
}

