long __cdecl file_seek_current_source(long offset)

{
  long lVar1;
  
  lVar1 = _lseek(g_source_handle,offset,0);
  return lVar1;
}

