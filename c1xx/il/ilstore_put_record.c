void __thiscall ilstore_put_record(c1_il_buffer *buf,int key,int value)

{
  c1_u8 *pcVar1;
  int iVar2;
  
  pcVar1 = (buf->bytes).start;
  if ((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
     (g_opt_Zg == '\0')) {
    if (buf->open != '\0') {
      iVar2 = (*g_ilmod->vtbl->put_record)
                        (key,CONCAT31((int3)((uint)pcVar1 >> 8),buf->ilstore_space),pcVar1,
                         (int)(buf->bytes).cur - (int)pcVar1,value);
      if (iVar2 != 0) goto LAB_1048c11c;
    }
    ilstore_report_error();
  }
LAB_1048c11c:
  (buf->bytes).cur = (buf->bytes).start;
  return;
}

