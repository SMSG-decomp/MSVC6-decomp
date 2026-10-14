int __cdecl format_declspec_attributes(int buf,uint storage,void *declspec,int unused)

{
  int buf_00;
  char *s;
  
  buf_00 = format_buffer_alloc();
  if ((storage & 0x80000) != 0) {
    format_buffer_append_string(buf_00,"dllimport ");
  }
  if ((storage & 0x40000) != 0) {
    format_buffer_append_string(buf_00,"dllexport ");
  }
  if ((storage & 0x10000) != 0) {
    format_buffer_append_string(buf_00,"naked ");
  }
  if ((storage & 0x20000) != 0) {
    format_buffer_append_string(buf_00,"thread ");
  }
  if ((storage & 0x1000000) != 0) {
    format_buffer_append_string(buf_00,"allocate(\"");
    format_buffer_append_string(buf_00,*(char **)(*(int *)((int)declspec + 8) + 4));
    format_buffer_append_string(buf_00,"\") ");
  }
  if ((storage & 0x400000) != 0) {
    format_buffer_append_string(buf_00,"selectany ");
  }
  s = format_buffer_text(buf_00);
  if (*s != '\0') {
    format_buffer_append_string(buf,"__declspec");
    format_buffer_append_char(buf,'(');
    format_buffer_append_string(buf,s);
    format_buffer_append_string(buf,") ");
  }
  format_buffer_free(buf_00);
  return buf;
}

