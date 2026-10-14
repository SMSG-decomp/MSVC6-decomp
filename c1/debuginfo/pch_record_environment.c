void pch_record_environment(void)

{
  fe_vector *pfVar1;
  fe_vector *pfVar2;
  c1_u8 *text;
  short sVar3;
  
  block_list_open_or_rewind(&g_pch_record_list);
  pfVar2 = g_define_list;
  for (sVar3 = 0; (pfVar2 != (fe_vector *)0x0 && ((int)sVar3 < (int)(uint)pfVar2->count));
      sVar3 = sVar3 + 1) {
    pragma_section_record(4,0,pfVar2->data[sVar3]);
  }
  text = cwd_string();
  pragma_section_record(7,0,(char *)text);
  pfVar2 = g_include_path_list;
  for (sVar3 = 0;
      (pfVar1 = g_forced_include_list, pfVar2 != (fe_vector *)0x0 &&
      ((int)sVar3 < (int)(uint)pfVar2->count)); sVar3 = sVar3 + 1) {
    pragma_section_record(7,0,pfVar2->data[sVar3]);
  }
  for (sVar3 = 0; (pfVar1 != (fe_vector *)0x0 && ((int)sVar3 < (int)(uint)pfVar1->count));
      sVar3 = sVar3 + 1) {
    pragma_section_record(5,0,pfVar1->data[sVar3]);
  }
  return;
}

