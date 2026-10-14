char * __cdecl load_message(UINT id)

{
  HMODULE hInstance;
  int len_2;
  char *lpBuffer;
  int len;
  
  len = 0x100;
  lpBuffer = g_message_buffer;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  len_2 = LoadStringA(hInstance,id,lpBuffer,len);
  if (len_2 == 0) {
    g_message_buffer[0] = '\0';
  }
  return g_message_buffer;
}

