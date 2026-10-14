void * __cdecl decorate_name_RTTI0(c1_type *type)

{
  char *pcVar1;
  void *pvVar2;
  
  builtin_strncpy(g_decorated_name,"??_R0",5);
  g_decorate_output_base = g_decorated_name;
  pcVar1 = decorate_name_3(g_decorated_name + 5,g_decorated_name,type,'\0');
  pcVar1[-1] = '@';
  *pcVar1 = '8';
  pcVar1[1] = '\0';
  pvVar2 = name_intern(g_decorated_name);
  return pvVar2;
}

