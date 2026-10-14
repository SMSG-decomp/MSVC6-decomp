int __cdecl pp_include_open_file_2(byte *name,char angle)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  
  if (g_include_depth == 0) {
    if ((g_create_pch_header_name != (char *)0x0) &&
       (cVar1 = file_name_equal((byte *)g_create_pch_header_name,name), cVar1 != '\0')) {
      g_pch_create_header_seen = '\x01';
    }
    if (g_pch_directive_mode != 0) {
      iVar4 = pch_record_include(name);
      if (iVar4 != 1) {
        if ((iVar4 != 2) || (g_pch_directive_mode == 1)) goto LAB_10433254;
        pp_warn_extra_tokens("#include");
      }
      return -4;
    }
  }
LAB_10433254:
  if ((g_compile_flags_cc & 0x1000000) == 0) {
    pp_warn_extra_tokens("#include");
  }
  pbVar2 = (byte *)pp_include_alias_lookup(g_include_alias_table,(char *)name,&angle);
  if (pbVar2 != (byte *)0x0) {
    name = pbVar2;
  }
  pcVar3 = strchr(g_opt_pc,(uint)*name);
  if ((pcVar3 == (char *)0x0) &&
     (((pcVar3 = strchr(g_opt_pc,0x3a), pcVar3 == (char *)0x0 ||
       (((byte)_mbctype_exref[*name + 1] & 4) != 0)) || (name[1] != 0x3a)))) {
    if ((angle != '\0') || (iVar4 = pp_include_search_parents(name,'\x01',(byte *)0x0), iVar4 == -1)
       ) {
      iVar4 = pp_include_check_path((char *)name,1,(char *)0x0);
    }
  }
  else {
    iVar4 = file_open_or_fatal((char *)name,0,0,1,1);
    if (iVar4 == -1) {
      diag_fatal_file_errno(0x53,0x157,(char *)name);
      return -1;
    }
    if ((-1 < iVar4) && ((g_pch_directive_mode == 1 || (g_auto_pch_creating != 0)))) {
      pragma_section_attribute((char *)name,iVar4);
      return iVar4;
    }
  }
  return iVar4;
}

