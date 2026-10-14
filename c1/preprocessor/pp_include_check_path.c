int __cdecl pp_include_check_path(char *name,int report,char *found)

{
  bool bVar1;
  fe_vector *pfVar2;
  int iVar3;
  short sVar4;
  
  pfVar2 = g_include_path_list;
  bVar1 = false;
  sVar4 = 0;
  while ((pfVar2 != (fe_vector *)0x0 && (iVar3 = (int)sVar4, iVar3 < (int)(uint)pfVar2->count))) {
    sVar4 = sVar4 + 1;
    bVar1 = true;
    iVar3 = pp_include_search_path((byte *)name,pfVar2->data[iVar3],'\0',(char)report,(byte *)found)
    ;
    if (iVar3 != -1) {
      return iVar3;
    }
  }
  if (found != (char *)0x0) {
    *found = '\0';
  }
  if (bVar1) {
    if ((char)report != '\0') {
      diag_fatal_file_errno(0x53,0x157,name);
      return -1;
    }
    return -1;
  }
  diag_fatal(0x22,name);
}

