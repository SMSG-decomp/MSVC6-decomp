void __cdecl print_file_version(char *path)

{
  DWORD size;
  BOOL ok;
  BOOL ok_2;
  int digits;
  char *label;
  int digits_2;
  int digits_3;
  char num [32];
  uint len;
  DWORD handle;
  VS_FIXEDFILEINFO *ffi;
  void *info;
  uint ls;
  uint ms;
  char *text;
  
  size = GetFileVersionInfoSizeA(path,&handle);
  if (size != 0) {
    info = xmalloc(size);
    ok = GetFileVersionInfoA(path,0,size,info);
    if (ok != 0) {
      ok_2 = VerQueryValueA(info,"\\",&ffi,&len);
      if (ok_2 != 0) {
        ms = ffi->dwFileVersionMS;
        ls = ffi->dwFileVersionLS;
        num[0] = ' ';
        digits = uint_to_string(ms >> 0x10,num + 1,10);
        text = num + digits + -1;
        label = load_message(0x137);
        msg_write(2,"%s %s.",label,text);
        num[0] = '0';
        digits_2 = uint_to_string(ms & 0xffff,num + 1,10);
        msg_write(2,"%s.",num + digits_2 + -1);
        strcpy(num,"000");
        digits_3 = uint_to_string(ls >> 0x10,num + 3,10);
        msg_write(2,"%s.%d",num + digits_3 + -1,ls & 0xffff);
      }
    }
    xfree(info);
  }
  return;
}

