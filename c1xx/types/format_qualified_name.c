void __cdecl format_qualified_name(int buf,byte *sym)

{
  byte bVar1;
  char *s;
  
  if (sym == (byte *)0x0) {
    return;
  }
  if ((*sym & 0x1f) != 0x16) {
    if (*(short *)(sym + 6) != 0) {
      format_qualified_name(buf,&g_scope_vector->entries[*(short *)(sym + 6)]->kind);
      format_buffer_append_string(buf,"::");
    }
    bVar1 = *sym & 0x1f;
    if (bVar1 == 4) {
      if ((*(byte *)(*(int *)(sym + 0x24) + 0x3e) & 1) != 0) {
        format_class_template_instance_name(buf,(c1_symbol *)sym);
        return;
      }
    }
    else {
      if (((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) {
        format_buffer_append_string(buf,*(char **)(*(int *)(sym + 8) + 4));
        return;
      }
      if ((*(byte *)(*(int *)(sym + 0x14) + 6) & 1) != 0) {
        format_buffer_append_string(buf,"`anonymous-namespace\'");
        return;
      }
    }
    format_buffer_append_string(buf,*(char **)(*(int *)(sym + 8) + 4));
    return;
  }
  s = format_template_parameter_name(*(short *)(*(int *)(sym + 0x14) + 8));
  format_buffer_append_string(buf,s);
  return;
}

