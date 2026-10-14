void __cdecl misc_strings_load(void)

{
  c1xx_misc_string *pcVar1;
  c1_u32 cVar2;
  char *pcVar3;
  c1xx_misc_string *row;
  CHAR local_100 [256];
  
  row = g_misc_strings;
  cVar2 = g_misc_strings[0].id;
  while (cVar2 != 0) {
    LoadStringA(g_module_handle,row->id,local_100,0x100);
    pcVar3 = _strdup(local_100);
    row->text = pcVar3;
    pcVar1 = row + 1;
    row = row + 1;
    cVar2 = pcVar1->id;
  }
  return;
}

