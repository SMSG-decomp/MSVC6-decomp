void __fastcall coff_hash32_resolve(uint32_t target_id,uint32_t symbol_index)

{
  c2_coff_pending_ref *pcVar1;
  c2_coff_pending_ref *pcVar2;
  c2_coff_pending_ref *pcVar3;
  
  pcVar2 = (c2_coff_pending_ref *)0x0;
  for (pcVar1 = g_coff_pending_refs[target_id & 0x1f]; pcVar1 != (c2_coff_pending_ref *)0x0;
      pcVar1 = pcVar1->next) {
    pcVar3 = pcVar1;
    if (pcVar1->key == target_id) {
      pcVar1->reloc->symbol_index = symbol_index;
      pcVar3 = pcVar2;
      if (pcVar2 == (c2_coff_pending_ref *)0x0) {
        g_coff_pending_refs[target_id & 0x1f] = pcVar1->next;
      }
      else {
        pcVar2->next = pcVar1->next;
      }
    }
    pcVar2 = pcVar3;
  }
  return;
}

