void __thiscall ilstore_open_stream(fe_il_buffer *buf,char *prefix,char *suffix)

{
  Stream *this;
  char *szStream;
  int iVar1;
  
  szStream = str_concat_malloc(prefix,suffix);
  buf->ilstore_stream_name = szStream;
  iVar1 = (*g_ilstore_pdb->vtbl->OpenStream)(g_ilstore_pdb,szStream,&buf->ilstore_stream);
  if ((iVar1 != 0) &&
     (this = buf->ilstore_stream, iVar1 = (*this->vtbl->Replace)(this,(void *)0x0,0), iVar1 != 0)) {
    return;
  }
  ilstore_report_error();
  return;
}

