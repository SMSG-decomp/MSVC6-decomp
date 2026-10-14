int __cdecl file_open_or_fatal(char *file,uint hash,int mode,int arg,int report)

{
  fe_name *name;
  int *piVar1;
  int handle;
  fe_name *canonical_name;
  
  if (mode == 2) {
    block_list_rewind(g_injected_text_list);
    piVar1 = file_record_lookup_or_new(g_current_scope,file,hash);
    pp_include_push_file(piVar1,2,-2,(byte)arg);
    return -2;
  }
  if (file == (char *)0x0) {
    handle = *(int *)(_iob_exref + 0x10);
    piVar1 = (int *)report;
  }
  else {
    name = name_intern_file_name(file);
    piVar1 = (int *)file_record_find_canonical(g_current_scope,(int)name);
    if ((piVar1 != (int *)0x0) && ((piVar1[3] & 0xff000000U) != 0)) {
      return -3;
    }
    handle = file_open_read_retry(file);
    if (handle == -1) {
      if (mode == 1) {
        diag_fatal_file_errno(0x53,0x155,file);
      }
      return -1;
    }
    if (piVar1 == (int *)0x0) {
      canonical_name = name;
      if (g_opt_FC == '\0') {
        name = name_intern(file);
      }
      piVar1 = (int *)include_record_new(name,canonical_name);
    }
  }
  pp_include_push_file(piVar1,mode,handle,(byte)arg);
  if (((file != (char *)0x0) && ((char)report != '\0')) && (g_opt_Bshow_incl != '\0')) {
    pragma_message_indent(g_include_depth,file);
  }
  return handle;
}

