void * __cdecl name_intern_file_name(char *file)

{
  void *pvVar1;
  char local_200 [512];
  
  file_make_canonical_path(local_200,file,0x200);
  pvVar1 = name_intern(local_200);
  return pvVar1;
}

