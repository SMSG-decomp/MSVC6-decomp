int __cdecl
format_declspec_prefix
          (int buf,uint bits,void *segment,int spec_08,int uuid,int spec_10,byte class_flags)

{
  int buf_00;
  void *pvVar1;
  char *s;
  
  buf_00 = format_buffer_alloc();
  if ((bits & 0x80000) != 0) {
    format_buffer_append_string(buf_00,"dllimport ");
  }
  if ((bits & 0x40000) != 0) {
    format_buffer_append_string(buf_00,"dllexport ");
  }
  if ((bits & 0x10000) != 0) {
    format_buffer_append_string(buf_00,"naked ");
  }
  if ((bits & 0x20000) != 0) {
    format_buffer_append_string(buf_00,"thread ");
  }
  if ((bits & 0x1000000) != 0) {
    format_buffer_append_string(buf_00,"allocate(\"");
    format_buffer_append_string(buf_00,*(char **)(*(int *)((int)segment + 8) + 4));
    format_buffer_append_string(buf_00,"\") ");
  }
  if ((bits & 0x4000) != 0) {
    format_buffer_append_string(buf_00,"uuid(\"");
    pvVar1 = guid_format_registry((void *)uuid);
    format_buffer_append_string(buf_00,*(char **)((int)pvVar1 + 4));
    format_buffer_append_string(buf_00,"\") ");
  }
  if (((bits & 0x10000000) != 0) && ((bits & 0x20000000) == 0)) {
    format_buffer_append_string(buf_00,"nothrow ");
  }
  if ((bits & 0x400000) != 0) {
    format_buffer_append_string(buf_00,"selectany ");
  }
  if ((class_flags & 2) != 0) {
    format_buffer_append_string(buf_00,"novtable ");
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

