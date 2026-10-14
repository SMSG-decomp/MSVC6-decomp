char * __fastcall find_message(int id)

{
  c2_message_prefix *pcVar1;
  uint32_t uVar2;
  c2_message_prefix *pcVar3;
  
  pcVar3 = g_message_prefix_table;
  uVar2 = g_message_prefix_table[0].id;
  while ((uVar2 != 0 && (uVar2 != id))) {
    pcVar1 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
    uVar2 = pcVar1->id;
  }
  return pcVar3->text;
}

