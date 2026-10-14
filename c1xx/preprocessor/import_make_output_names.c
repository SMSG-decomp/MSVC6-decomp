void __cdecl import_make_output_names(char *tlb,char **tlh,char **tli)

{
  c1_u8 *pcVar1;
  char local_308 [4];
  char local_304 [256];
  char local_204 [260];
  char local_100 [256];
  
  if (g_object_file_name == (char *)0x0) {
    local_304[0] = '\0';
    local_308[0] = '\0';
  }
  else {
    _splitpath(g_object_file_name,local_308,local_304,(char *)0x0,(char *)0x0);
  }
  _splitpath(tlb,(char *)0x0,(char *)0x0,local_100,(char *)0x0);
  if (g_import_implementation_only == 0) {
    _makepath(local_204,local_308,local_304,local_100,".tlh");
    pcVar1 = str_dup_arena(local_204,5);
    *tlh = (char *)pcVar1;
  }
  else {
    *tlh = (char *)0x0;
  }
  if (g_import_no_implementation != 0) {
    *tli = (char *)0x0;
    return;
  }
  _makepath(local_204,local_308,local_304,local_100,".tli");
  pcVar1 = str_dup_arena(local_204,5);
  *tli = (char *)pcVar1;
  return;
}

