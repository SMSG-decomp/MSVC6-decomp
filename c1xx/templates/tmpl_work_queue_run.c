void __fastcall tmpl_work_queue_run(c1_tmpl_work_item **queue)

{
  c1_tmpl_work_item *pcVar1;
  
  for (pcVar1 = *queue; pcVar1 != (c1_tmpl_work_item *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->armed != '\0') {
      (**(code **)pcVar1->vtbl)();
    }
  }
  return;
}

