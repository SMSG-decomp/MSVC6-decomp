void __thiscall import_flush_text_to_file(c1_il_buffer *buf,void *stream,char *path)

{
  c1_u8 *_Str;
  size_t _Count;
  
  _Str = (buf->bytes).start;
  _Count = (int)(buf->bytes).cur - (int)_Str;
  if (_Count != 0) {
    fwrite(_Str,1,_Count,stream);
    if ((*(byte *)((int)stream + 0xc) & 0x20) != 0) {
      diag_fatal_file_errno(0x55,0x154,path);
    }
    (buf->bytes).cur = (buf->bytes).start;
  }
  return;
}

