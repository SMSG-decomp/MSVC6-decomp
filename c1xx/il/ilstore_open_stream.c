void __thiscall ilstore_open_stream(c1_il_buffer *buf,char *prefix,char *suffix)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = str_concat_malloc(prefix,suffix);
  buf->ilstore_stream_name = pcVar1;
  iVar2 = (*g_ilstore_pdb->vtbl->open_stream)(pcVar1,&buf->ilstore_stream);
  if ((iVar2 != 0) && (iVar2 = (*buf->ilstore_stream->vtbl->replace)(0,0), iVar2 != 0)) {
    return;
  }
  ilstore_report_error();
  return;
}

