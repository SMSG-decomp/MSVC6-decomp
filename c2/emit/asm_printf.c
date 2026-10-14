int __cdecl asm_printf(char *fmt,...)

{
  int iVar1;
  
  if (g_listing_file != (FILE *)0x0) {
    iVar1 = vfprintf(g_listing_file,fmt,&stack0x00000008);
    return iVar1;
  }
  iVar1 = vfprintf((FILE *)(_iob_exref + 0x20),fmt,&stack0x00000008);
  return iVar1;
}

