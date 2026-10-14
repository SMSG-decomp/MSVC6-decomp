void __fastcall coff_hash32_insert(uint32_t target_id,c2_coff_reloc *reloc)

{
  c2_coff_pending_ref *pcVar1;
  
  pcVar1 = (*g_coff_alloc_fn)(0xc);
  pcVar1->key = target_id;
  pcVar1->reloc = reloc;
  pcVar1->next = g_coff_pending_refs[target_id & 0x1f];
  g_coff_pending_refs[target_id & 0x1f] = pcVar1;
  return;
}

