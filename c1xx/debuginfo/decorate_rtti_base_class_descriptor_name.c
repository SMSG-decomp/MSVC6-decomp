void * __cdecl
decorate_rtti_base_class_descriptor_name(byte *cls,int mdisp,int pdisp,int vdisp,uint attributes)

{
  char *pcVar1;
  void *pvVar2;
  
  builtin_strncpy(g_decorated_name,"??_R1",5);
  g_decorate_output_base = g_decorated_name;
  g_decorate_template_arg_backref_count = 0;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  pcVar1 = decorate_signed_number(g_decorated_name + 5,mdisp);
  pcVar1 = decorate_signed_number(pcVar1,pdisp);
  pcVar1 = decorate_signed_number(pcVar1,vdisp);
  pcVar1 = decorate_number(pcVar1,attributes);
  pcVar1 = decorate_scope_chain(pcVar1,cls);
  *pcVar1 = '@';
  pcVar1[1] = '8';
  pcVar1[2] = '\0';
  pvVar2 = name_intern(g_decorated_name);
  return pvVar2;
}

