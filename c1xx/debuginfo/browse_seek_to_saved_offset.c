bool __cdecl browse_seek_to_saved_offset(void)

{
  int iVar1;
  
  iVar1 = fseek((FILE *)g_browse_sbr_file,g_browse_sbr_header_end,0);
  return (bool)('\x01' - (iVar1 != 0));
}

