c2_pdb_object_code * enc_open_previous_object(void)

{
  char *pcVar1;
  FILE *_File;
  char *message;
  int iVar2;
  c2_pdb_object_code *pcStack_4;
  
  if (g_opt_object_path == (char *)0x0) {
    fatal_error(0x25,"");
  }
  pcVar1 = enc_file_name(g_opt_object_path);
  _File = fopen(pcVar1,"r");
  if (_File == (FILE *)0x0) {
    pcVar1 = enc_file_name(g_opt_object_path);
    message = load_message(0x136);
    fatal_error_errno(0x53,message,pcVar1);
  }
  fclose(_File);
  iVar2 = ObjectCodeGet(&pcStack_4,0x14c,pcVar1);
  if (iVar2 == 0) {
    fatal_error(0x25,pcVar1);
  }
  return pcStack_4;
}

