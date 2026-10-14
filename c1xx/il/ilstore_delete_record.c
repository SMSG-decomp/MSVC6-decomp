void __thiscall ilstore_delete_record(c1_il_buffer *buf,int key)

{
  int iVar1;
  
  if ((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
     (g_opt_Zg == '\0')) {
    if ((buf->open != '\0') &&
       (iVar1 = (*g_ilmod->vtbl->delete_record)(key,buf->ilstore_space), iVar1 != 0)) {
      return;
    }
    ilstore_report_error();
  }
  return;
}

