int __cdecl pp_include_open_file_2_fragment(byte *name,char angle,byte *file_name)

{
  byte *pbVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = pch_record_include(file_name);
  if (iVar3 != 1) {
    if ((iVar3 != 2) || (g_pch_directive_mode == 1)) {
      pp_warn_extra_tokens("#include");
      pbVar1 = (byte *)pp_include_alias_lookup(g_include_alias_table,(char *)file_name,&angle);
      if (pbVar1 != (byte *)0x0) {
        file_name = pbVar1;
      }
      pcVar2 = strchr(g_opt_pc,(uint)*file_name);
      if ((pcVar2 == (char *)0x0) &&
         (((pcVar2 = strchr(g_opt_pc,0x3a), pcVar2 == (char *)0x0 ||
           (((byte)_mbctype_exref[*file_name + 1] & 4) != 0)) || (file_name[1] != 0x3a)))) {
        if ((angle != '\0') ||
           (iVar3 = pp_include_search_parents(file_name,'\x01',(byte *)0x0), iVar3 == -1)) {
          iVar3 = pp_include_check_path((char *)file_name,1,(char *)0x0);
        }
      }
      else {
        iVar3 = file_open_or_fatal((char *)file_name,0,0,1,1);
        if (iVar3 == -1) {
          diag_fatal_file_errno(0x53,0x157,(char *)file_name);
          return -1;
        }
        if ((-1 < iVar3) && ((g_pch_directive_mode == 1 || (g_auto_pch_creating != 0)))) {
          pragma_section_attribute((char *)file_name,iVar3);
          return iVar3;
        }
      }
      return iVar3;
    }
    pp_warn_extra_tokens("#include");
  }
  return -4;
}

