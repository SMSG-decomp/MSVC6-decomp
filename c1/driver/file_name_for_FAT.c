c1_u8 * __cdecl file_name_for_FAT(c1_u8 *file)

{
  c1_u8 *_FullPath;
  char local_304 [4];
  char ext [256];
  char fname [256];
  char local_100 [256];
  
  if (g_opt_FAT == 0) {
    return file;
  }
  _FullPath = str_dup_arena((char *)file,3);
  _splitpath((char *)_FullPath,local_304,local_100,fname,ext);
  fname[8] = '\0';
  ext[4] = '\0';
  _makepath((char *)_FullPath,local_304,local_100,fname,ext);
  return _FullPath;
}

