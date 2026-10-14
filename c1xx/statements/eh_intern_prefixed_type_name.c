void * __cdecl eh_intern_prefixed_type_name(c1_type *type,char *prefix)

{
  int iVar1;
  void *pvVar2;
  char local_1800 [6140];
  undefined4 uStack_4;
  
  uStack_4 = 0x104aa4a2;
  iVar1 = format_snprintf(local_1800,"%s",0x1800,prefix);
  decorate_name_3(local_1800 + iVar1,local_1800,type,'\0');
  pvVar2 = name_intern(local_1800);
  return pvVar2;
}

