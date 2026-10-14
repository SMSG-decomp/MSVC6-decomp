char * __cdecl decorate_string_literal_name(int *literal,char wide)

{
  char *pcVar1;
  
  g_decorate_template_arg_backref_count = 0;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  g_decorate_output_base = g_decorated_name;
  pcVar1 = decorate_string_literal_name_body
                     (g_decorated_name,(byte *)*literal,(uint)*(ushort *)(literal + 1),wide);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
    return g_decorated_name;
  }
  return (char *)0x0;
}

