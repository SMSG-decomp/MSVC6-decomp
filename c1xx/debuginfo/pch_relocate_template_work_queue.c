void __cdecl pch_relocate_template_work_queue(void)

{
  c1_tmpl_work_item *pcVar1;
  c1_tmpl_work_queue *pcVar2;
  
  pcVar2 = g_template_work_queue;
  if (g_template_work_queue == (c1_tmpl_work_queue *)0x0) {
    return;
  }
  pch_relocate_slot_once(&g_pch_image,(uint *)g_template_work_queue);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->last);
  pcVar1 = pcVar2->first;
  if (pcVar1 != (c1_tmpl_work_item *)0x0) {
    (**(code **)((int)pcVar1->vtbl + 4))();
    return;
  }
  return;
}

