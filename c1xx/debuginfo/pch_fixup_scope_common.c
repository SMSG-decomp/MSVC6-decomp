void __fastcall pch_fixup_scope_common(c1xx_hash_scope *scope)

{
  c1_using_directive *pcVar1;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)&scope->outer);
  pch_relocate_slot_once(&g_pch_image,(uint *)&scope->parent);
  pch_relocate_slot_once(&g_pch_image,(uint *)&scope->usings);
  pcVar1 = scope->usings;
  if (pcVar1 != (c1_using_directive *)0x0) {
    pch_relocate_slot_once(&g_pch_image,(uint *)pcVar1);
    pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar1->ns);
    pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar1->visible_in);
    pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar1->next);
    pcVar1 = pcVar1->next;
    if (pcVar1 != (c1_using_directive *)0x0) {
      pch_fixup_scope_record_chain((int)pcVar1);
    }
  }
  return;
}

