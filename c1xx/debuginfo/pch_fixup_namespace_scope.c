void __fastcall pch_fixup_namespace_scope(c1xx_namespace_scope *hash_scope)

{
  pch_fixup_hash_scope((c1xx_hash_scope *)hash_scope);
  pch_relocate_slot_once(&g_pch_image,(uint *)&hash_scope->ns);
  return;
}

