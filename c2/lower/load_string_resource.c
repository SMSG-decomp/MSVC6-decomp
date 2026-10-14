char * __fastcall load_string_resource(UINT id,char *buf,int size)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = LoadStringA(g_c2_module_handle,id,buf,size);
  if (iVar1 != 0) {
    pcVar2 = unescape_string(buf);
    return pcVar2;
  }
  return (char *)0x0;
}

