int __cdecl file_copy_contents(void *from,void *to,uint n)

{
  size_t sVar1;
  uint uVar2;
  
  uVar2 = n;
  do {
    if ((int)uVar2 < 0x8000) {
      sVar1 = uVar2 & 0xffff;
    }
    else {
      sVar1 = 0x8000;
    }
    sVar1 = fread(g_file_copy_buffer,1,sVar1,from);
    uVar2 = uVar2 - sVar1;
    if ((*(byte *)((int)from + 0xc) & 0x20) != 0) {
      diag_fatal_file_errno(0x54,0x153,(char *)0x0);
    }
    _g_io_result = fwrite(g_file_copy_buffer,1,sVar1,to);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x153,(char *)0x0);
    }
  } while (sVar1 == 0x8000);
  return n - uVar2;
}

