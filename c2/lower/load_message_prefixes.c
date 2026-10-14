void load_message_prefixes(void)

{
  c2_message_prefix *pcVar1;
  uint32_t uVar2;
  char *pcVar3;
  c2_message_prefix *pcVar4;
  
  if (g_message_prefixes_loaded == 0) {
    pcVar4 = g_message_prefix_table;
    g_message_prefixes_loaded = 1;
    uVar2 = g_message_prefix_table[0].id;
    while (uVar2 != 0) {
      pcVar3 = format_message(pcVar4->id);
      if (pcVar3 == (char *)0x0) {
        if (pcVar4->id == 0x12d) {
          pcVar4->text = "warning";
        }
        if (pcVar4->id == 0x12e) {
          pcVar4->text = "error";
        }
        if (pcVar4->id == 0x12f) {
          pcVar4->text = "fatal error";
        }
      }
      else {
        pcVar3 = _strdup(pcVar3);
        pcVar4->text = pcVar3;
      }
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
      uVar2 = pcVar1->id;
    }
  }
  return;
}

