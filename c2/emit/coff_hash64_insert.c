void __fastcall coff_hash64_insert(uint32_t key,uint32_t symbol_index)

{
  c2_coff_key_entry *pcVar1;
  
  pcVar1 = (*g_coff_alloc_fn)(0xc);
  pcVar1->key = key;
  pcVar1->symbol_index = symbol_index;
  pcVar1->next = g_coff_symbol_key_hash[key & 0x3f];
  g_coff_symbol_key_hash[key & 0x3f] = pcVar1;
  return;
}

