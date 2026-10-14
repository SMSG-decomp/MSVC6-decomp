long __cdecl file_tell_current_source(void)

{
  long lVar1;
  
  lVar1 = _tell(g_source_handle);
  return lVar1;
}

