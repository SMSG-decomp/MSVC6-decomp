void __cdecl pch_record_environment(void)

{
  c1_vector *pcVar1;
  c1_vector *pcVar2;
  c1_u8 *text;
  short sVar3;
  
  block_list_open_or_rewind((c1_byte_block_list **)&g_pch_record_list);
  pcVar2 = g_define_list;
  for (sVar3 = 0; (pcVar2 != (c1_vector *)0x0 && ((int)sVar3 < (int)(uint)pcVar2->count));
      sVar3 = sVar3 + 1) {
    pragma_section_record(4,0,pcVar2->data[sVar3]);
  }
  text = cwd_string();
  pragma_section_record(7,0,(char *)text);
  pcVar2 = g_include_path_list;
  for (sVar3 = 0;
      (pcVar1 = g_forced_include_list, pcVar2 != (c1_vector *)0x0 &&
      ((int)sVar3 < (int)(uint)pcVar2->count)); sVar3 = sVar3 + 1) {
    pragma_section_record(7,0,pcVar2->data[sVar3]);
  }
  for (sVar3 = 0; (pcVar1 != (c1_vector *)0x0 && ((int)sVar3 < (int)(uint)pcVar1->count));
      sVar3 = sVar3 + 1) {
    pragma_section_record(5,0,pcVar1->data[sVar3]);
  }
  return;
}

