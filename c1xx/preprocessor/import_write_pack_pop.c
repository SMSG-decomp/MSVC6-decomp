void __cdecl import_write_pack_pop(void)

{
  if (g_import_implementation_only == 0) {
    fprintf((FILE *)g_import_tlh_file,"\n#pragma pack(pop)\n");
    if ((g_import_tlh_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x55,0x154,g_import_tlh_path);
    }
  }
  return;
}

