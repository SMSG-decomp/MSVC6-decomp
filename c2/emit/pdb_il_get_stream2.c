FILE * __fastcall pdb_il_get_stream2(uint32_t key,int mod)

{
  int iVar1;
  
  iVar1 = ILModGetIL(g_pdb_il_modules[mod],key,2,&g_pdb_il_buffer,0);
  if (iVar1 == 0) {
    return (FILE *)0x0;
  }
  g_pdb_il_file._cnt = g_pdb_il_buffer.size;
  g_pdb_il_file._ptr = g_pdb_il_buffer.data;
  return &g_pdb_il_file;
}

