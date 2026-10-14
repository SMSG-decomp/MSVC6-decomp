int __cdecl diag_fatal_file(int err,int n,int what,char *file)

{
  if ((g_compile_phase != 7) && (g_compile_phase != 6)) {
    if (file == (char *)0x0) {
      file = "";
    }
    diag_fatal(n,what,file,0x45,err);
  }
  return 0;
}

