char * __cdecl decorate_special_name(byte *sym,char kind)

{
  char *pcVar1;
  
  builtin_strncpy(g_decorated_name,"??_R",4);
  g_decorate_output_base = g_decorated_name;
  g_decorate_template_arg_backref_count = 0;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  g_decorated_name[4] = kind;
  pcVar1 = decorate_scope_chain(g_decorated_name + 5,sym);
  *pcVar1 = '@';
  pcVar1[1] = '8';
  pcVar1[2] = '\0';
  return g_decorated_name;
}

