fe_name * __cdecl name_new_S(void)

{
  uint uVar1;
  fe_name *pfVar2;
  char local_20 [32];
  
  uVar1 = g_name_S_counter;
  g_name_S_counter = g_name_S_counter + 1;
  sprintf(local_20,"$S%u",uVar1);
  pfVar2 = name_intern(local_20);
  return pfVar2;
}

