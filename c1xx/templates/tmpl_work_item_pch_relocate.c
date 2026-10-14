void __fastcall tmpl_work_item_pch_relocate(c1_tmpl_work_item *item)

{
  c1_tmpl_work_item *pcVar1;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)&item->sym);
  pch_relocate_slot_once(&g_pch_image,(uint *)&item->next);
  pcVar1 = item->next;
  if (pcVar1 != (c1_tmpl_work_item *)0x0) {
    (**(code **)((int)pcVar1->vtbl + 4))();
    return;
  }
  return;
}

