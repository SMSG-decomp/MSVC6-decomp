void __fastcall tmpl_function_item_pch_relocate(c1xx_tmpl_function_item *item)

{
  void *pvVar1;
  char cVar2;
  uint *puVar3;
  
  tmpl_work_item_pch_relocate((c1_tmpl_work_item *)item);
  pch_relocate_slot_once(&g_pch_image,(uint *)&item->tmpl);
  pch_relocate_slot_once(&g_pch_image,(uint *)&item->args);
  cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)&item->parameter_scope);
  if (cVar2 != '\0') {
    pvVar1 = item->parameter_scope;
    pch_relocate_slot_once(&g_pch_image,(uint *)((int)pvVar1 + 8));
    puVar3 = (uint *)((int)pvVar1 + 4);
    cVar2 = pch_relocate_slot_once(&g_pch_image,puVar3);
    if (cVar2 != '\0') {
      puVar3 = (uint *)*puVar3;
      pch_relocate_slot_once(&g_pch_image,puVar3);
      pch_relocate_symbol((byte *)(puVar3 + -2));
      pch_relocate_slot_once(&g_pch_image,puVar3 + 7);
      cVar2 = pch_relocate_slot_once(&g_pch_image,puVar3 + 1);
      if (cVar2 != '\0') {
        pch_relocate_symbol_list_simple(puVar3[1]);
      }
    }
  }
  return;
}

