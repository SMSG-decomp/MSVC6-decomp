void __fastcall coff_hash_remove(uint32_t key)

{
  c2_coff_key_entry *pcVar1;
  c2_coff_key_entry *pcVar2;
  
  pcVar1 = (c2_coff_key_entry *)(g_coff_symbol_key_hash + (key & 0x3f));
  for (pcVar2 = g_coff_symbol_key_hash[key & 0x3f]; pcVar2 != (c2_coff_key_entry *)0x0;
      pcVar2 = pcVar2->next) {
    if (pcVar2->key == key) {
      pcVar1->next = pcVar2->next;
      pcVar2 = pcVar1;
    }
    pcVar1 = pcVar2;
  }
  return;
}

