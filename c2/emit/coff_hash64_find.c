uint32_t __fastcall coff_hash64_find(uint32_t key,int16_t want_defined)

{
  c2_coff_key_entry *pcVar1;
  
  pcVar1 = g_coff_symbol_key_hash[key & 0x3f];
  do {
    if (pcVar1 == (c2_coff_key_entry *)0x0) {
      return 0;
    }
    if (pcVar1->key == key) {
      if (*(short *)((int)g_coff_symbol_slots[pcVar1->symbol_index]->payload + 0xc) == 0) {
        if (want_defined == 0) goto LAB_107829bd;
      }
      else if (want_defined != 0) {
LAB_107829bd:
        return pcVar1->symbol_index;
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

