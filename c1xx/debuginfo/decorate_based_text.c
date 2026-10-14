int __cdecl decorate_based_text(uchar flags,int base)

{
  int buf;
  char *s;
  
  buf = format_buffer_alloc();
  format_buffer_append_string(buf,"__based(");
  if ((flags & 0x18) == 8) {
    s = "void";
  }
  else {
    s = *(char **)(*(int *)(base + 8) + 4);
  }
  format_buffer_append_string(buf,s);
  format_buffer_append_string(buf,") ");
  return buf;
}

