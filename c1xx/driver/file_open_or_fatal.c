int __cdecl file_open_or_fatal(char *file,uint hash,int mode,int arg,int report)

{
  void *name;
  int *file_record;
  int handle;
  fe_file_record *file_record_00;
  void *b;
  
  if (mode == 2) {
    block_list_rewind(g_injected_text_list);
    file_record_00 = file_record_lookup_or_new(g_current_scope,file,hash);
    pp_include_push_file((int *)file_record_00,2,-2,(byte)arg);
    return -2;
  }
  if (file == (char *)0x0) {
    handle = *(int *)(_iob_exref + 0x10);
    file_record = (int *)report;
  }
  else {
    name = name_intern_file_name(file);
    file_record = (int *)file_record_find_canonical(g_current_scope,(int)name);
    if ((file_record != (int *)0x0) && ((file_record[3] & 0xff000000U) != 0)) {
      return -3;
    }
    handle = file_open_read_retry(file);
    if (handle == -1) {
      if (mode == 1) {
        diag_fatal_file_errno(0x53,0x155,file);
      }
      return -1;
    }
    if (file_record == (int *)0x0) {
      b = name;
      if (g_opt_FC == '\0') {
        name = name_intern(file);
      }
      file_record = (int *)include_record_new((int)name,(int)b);
    }
  }
  pp_include_push_file(file_record,mode,handle,(byte)arg);
  if (((file != (char *)0x0) && ((char)report != '\0')) && (g_opt_Bshow_incl != '\0')) {
    pragma_message_indent(g_include_depth,file);
  }
  return handle;
}

