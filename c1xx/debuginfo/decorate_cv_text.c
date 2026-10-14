int __cdecl decorate_cv_text(int buf,ushort quals)

{
  if ((quals & 0x20) != 0) {
    format_buffer_prepend_string(buf,"const ");
  }
  if ((quals & 0x40) != 0) {
    format_buffer_prepend_string(buf,"volatile ");
  }
  if ((quals & 0x100) != 0) {
    format_buffer_prepend_string(buf,"__restrict ");
  }
  return buf;
}

