void * __cdecl name_new_E(void)

{
  int iVar1;
  void *pvVar2;
  char local_20 [32];
  
  iVar1 = g_next_dollar_name;
  g_next_dollar_name = g_next_dollar_name + 1;
  sprintf(local_20,"$E%u",iVar1);
  pvVar2 = name_intern(local_20);
  return pvVar2;
}

