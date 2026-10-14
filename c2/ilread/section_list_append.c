void __fastcall section_list_append(c2_fe_symbol *sec)

{
  c2_fe_symbol_u32 *pcVar1;
  
  if (g_section_list != (c2_fe_symbol *)0x0) {
    pcVar1 = &g_section_list_tail->u32;
    g_section_list_tail = sec;
    pcVar1->next_section = sec;
    return;
  }
  g_section_list = sec;
  g_section_list_tail = sec;
  return;
}

