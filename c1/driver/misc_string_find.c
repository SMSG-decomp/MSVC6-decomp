char * __cdecl misc_string_find(int id)

{
  fe_misc_string *pfVar1;
  uint uVar2;
  fe_misc_string *pfVar3;
  
  pfVar3 = g_misc_strings;
  uVar2 = g_misc_strings[0].id;
  while ((uVar2 != 0 && (uVar2 != id))) {
    pfVar1 = pfVar3 + 1;
    pfVar3 = pfVar3 + 1;
    uVar2 = pfVar1->id;
  }
  return pfVar3->text;
}

