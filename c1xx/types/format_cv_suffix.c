int __cdecl format_cv_suffix(int buf,c1_type *this_type)

{
  char cVar1;
  int iVar2;
  char *s;
  
  if (this_type == (c1_type *)0x0) {
    return buf;
  }
  iVar2 = format_buffer_alloc();
  cVar1 = (char)this_type->code;
  while (cVar1 < '\0') {
    this_type = this_type->base;
    cVar1 = (char)this_type->code;
  }
  iVar2 = decorate_cv_text(iVar2,this_type->flags);
  s = format_buffer_text_trimmed(iVar2);
  if (*s != '\0') {
    format_buffer_append_char(buf,' ');
    format_buffer_append_string(buf,s);
  }
  format_buffer_free(iVar2);
  return buf;
}

