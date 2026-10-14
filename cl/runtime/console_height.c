int __cdecl console_height(void)

{
  HANDLE con;
  BOOL ok;
  int rows;
  _CONSOLE_SCREEN_BUFFER_INFO info;
  
  con = CreateFileA("CONOUT$",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (con != (HANDLE)0xffffffff) {
    ok = GetConsoleScreenBufferInfo(con,&info);
    CloseHandle(con);
    if (ok != 0) {
      rows = ((int)info.srWindow.Bottom - (int)info.srWindow.Top) + 1;
      if (0 < rows) {
        return rows;
      }
      return 1;
    }
  }
  return 0x19;
}

