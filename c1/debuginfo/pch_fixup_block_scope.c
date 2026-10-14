void __fastcall pch_fixup_block_scope(c1_scope_object *hash_scope)

{
  pch_relocate_slot_once(&g_pch_image,(uint)&hash_scope->parent);
  pch_relocate_slot_once(&g_pch_image,(uint)(hash_scope->pad09 + 3));
  return;
}

