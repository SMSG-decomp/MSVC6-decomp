int __cdecl diag_fatal_file_errno(int n,int what,char *file)

{
  int *piVar1;
  
  if ((g_compile_phase != 7) && (g_compile_phase != 6)) {
    if (file == (char *)0x0) {
      file = "";
    }
    piVar1 = _errno();
    diag_fatal(n,what,file,0x65,*piVar1);
  }
  return 0;
}

