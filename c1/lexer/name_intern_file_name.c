fe_name * __cdecl name_intern_file_name(char *file)

{
  fe_name *pfVar1;
  char local_200 [512];
  
  file_make_canonical_path(local_200,file,0x200);
  pfVar1 = name_intern(local_200);
  return pfVar1;
}

