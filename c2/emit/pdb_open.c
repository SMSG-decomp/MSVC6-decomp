int __fastcall pdb_open(char *pdb_path,char *obj_path)

{
  int iVar1;
  int pdb_error;
  char relative_obj [260];
  char stream_name [260];
  char error_text [1024];
  
  iVar1 = PDBOpen(pdb_path,"w",0,&pdb_error,error_text,&g_pdb);
  if (iVar1 == 0) {
    if (pdb_error == 0xb) {
      iVar1 = 0x12d;
    }
    else {
      iVar1 = 300;
    }
    fatal_error(iVar1,pdb_path);
  }
  g_pdb_name = pdb_path;
  if (g_opt_incremental != 0) {
    path_make_relative(pdb_path,obj_path,relative_obj);
    sprintf(stream_name,"/be/pi/mod/%s",relative_obj);
    iVar1 = PDBOpenStream(g_pdb,stream_name,&g_incr_info_stream);
    if (iVar1 == 0) {
      fatal_error(300,pdb_path);
    }
  }
  g_pdb_il_file._flag = 1;
  g_pdb_il_file._file = -1;
  return 1;
}

