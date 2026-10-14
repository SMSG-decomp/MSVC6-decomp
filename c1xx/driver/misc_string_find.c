char * __cdecl misc_string_find(int id)

{
  c1xx_misc_string *pcVar1;
  c1_u32 cVar2;
  c1xx_misc_string *row;
  
  row = g_misc_strings;
  cVar2 = g_misc_strings[0].id;
  while ((cVar2 != 0 && (cVar2 != id))) {
    pcVar1 = row + 1;
    row = row + 1;
    cVar2 = pcVar1->id;
  }
  return row->text;
}

