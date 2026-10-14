char * __cdecl file_name_for_FAT(char *file)

{
  c1_u8 *_FullPath;
  char local_304 [4];
  char local_300 [4];
  char path0;
  char local_200 [8];
  char path1;
  char local_100 [256];
  
  if (g_opt_FAT == 0) {
    return file;
  }
  _FullPath = str_dup_arena(file,5);
  _splitpath((char *)_FullPath,local_304,local_100,local_200,local_300);
  path1 = '\0';
  path0 = '\0';
  _makepath((char *)_FullPath,local_304,local_100,local_200,local_300);
  return (char *)_FullPath;
}

