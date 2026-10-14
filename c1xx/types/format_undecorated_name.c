int __cdecl format_undecorated_name(int buf,fe_name *name)

{
  uint uVar1;
  char *pcVar2;
  
  if (buf == 0) {
    buf = format_buffer_alloc();
  }
  uVar1 = 0x800;
  if ((g_format_name_flags & 1) != 0) {
    uVar1 = 0x1800;
  }
  if (g_undecorate_hook != (code *)0x0) {
    pcVar2 = (char *)(*g_undecorate_hook)
                               (0,name->text,0,format_undname_alloc,0,format_template_parameter_name
                                ,uVar1 | 0x4000);
    format_buffer_append_string(buf,pcVar2);
    return buf;
  }
  pcVar2 = (char *)__unDName(0,name->text,0,format_undname_alloc,0,uVar1);
  format_buffer_append_string(buf,pcVar2);
  return buf;
}

