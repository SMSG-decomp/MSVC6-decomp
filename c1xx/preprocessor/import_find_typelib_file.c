char * __cdecl import_find_typelib_file(char *file,char angle)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  c1_u8 *pcVar4;
  byte *pbVar5;
  byte local_304 [512];
  char local_104 [260];
  
  pcVar2 = strchr(g_opt_pc,(uint)(byte)*file);
  if ((pcVar2 == (char *)0x0) &&
     (((pcVar2 = strchr(g_opt_pc,0x3a), pcVar2 == (char *)0x0 ||
       (((byte)_mbctype_exref[(byte)*file + 1] & 4) != 0)) || (file[1] != ':')))) {
    pbVar5 = local_304;
    if ((((angle != '\0') ||
         (iVar3 = pp_include_search_parents((byte *)file,'\0',local_304), iVar3 != 0)) &&
        (bVar1 = import_search_env_path(file,"PATH",(char *)local_304), bVar1 == 0)) &&
       ((bVar1 = import_search_env_path(file,"LIB",(char *)local_304), bVar1 == 0 &&
        (iVar3 = pp_include_check_path(file,0,(char *)local_304), iVar3 != 0)))) {
      return (char *)0x0;
    }
  }
  else {
    iVar3 = _access(file,0);
    pbVar5 = (byte *)file;
    if (iVar3 != 0) {
      return (char *)0x0;
    }
  }
  pcVar2 = _fullpath(local_104,(char *)pbVar5,0x104);
  if (pcVar2 != (char *)0x0) {
    pcVar4 = str_dup_arena(local_104,5);
    return (char *)pcVar4;
  }
  return (char *)0x0;
}

