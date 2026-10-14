void __thiscall ilstore_put_record(fe_il_buffer *buf,int key,int value)

{
  PB puVar1;
  int iVar2;
  
  puVar1 = (buf->bytes).pbStart;
  if ((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
     (g_opt_Zg == '\0')) {
    if (buf->open != '\0') {
      iVar2 = (*g_ilmod->vtbl->PutIL)
                        (g_ilmod,key,buf->ilstore_space,puVar1,(int)(buf->bytes).pbEnd - (int)puVar1
                         ,(uchar)value);
      if (iVar2 != 0) goto LAB_106448e3;
    }
    ilstore_report_error();
  }
LAB_106448e3:
  (buf->bytes).pbEnd = (buf->bytes).pbStart;
  return;
}

