void __fastcall pch_fixup_block_scope(c1xx_hash_scope *scope)

{
  c1_sym_link *slot;
  char cVar1;
  c1_sym_link **ppcVar2;
  
  pch_fixup_scope_common(scope);
  cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&scope->buckets);
  if (cVar1 != '\0') {
    ppcVar2 = scope->buckets;
    pch_relocate_slot_once(&g_pch_image,(uint *)(ppcVar2 + 2));
    ppcVar2 = ppcVar2 + 1;
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)ppcVar2);
    if (cVar1 != '\0') {
      slot = *ppcVar2;
      pch_relocate_slot_once(&g_pch_image,(uint *)slot);
      pch_relocate_symbol((byte *)&slot[-1].position);
      pch_relocate_slot_once(&g_pch_image,(uint *)&slot[1].type);
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&slot->next);
      if (cVar1 != '\0') {
        pch_relocate_symbol_list_simple((int)slot->next);
      }
    }
  }
  return;
}

