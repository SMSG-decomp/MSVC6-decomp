void misc_strings_load(void)

{
  fe_misc_string *pfVar1;
  uint uVar2;
  char *pcVar3;
  fe_misc_string *pfVar4;
  CHAR local_100 [256];
  
  pfVar4 = g_misc_strings;
  uVar2 = g_misc_strings[0].id;
  while (uVar2 != 0) {
    LoadStringA(g_module_handle,pfVar4->id,local_100,0x100);
    pcVar3 = _strdup(local_100);
    pfVar4->text = pcVar3;
    pfVar1 = pfVar4 + 1;
    pfVar4 = pfVar4 + 1;
    uVar2 = pfVar1->id;
  }
  return;
}

