c1_tmpl_work_item * __thiscall tmpl_work_queue_find(c1_tmpl_work_item **queue,c1_symbol *sym)

{
  c1_tmpl_work_item *pcVar1;
  
  pcVar1 = *queue;
  while( true ) {
    if (pcVar1 == (c1_tmpl_work_item *)0x0) {
      return (c1_tmpl_work_item *)0x0;
    }
    if (pcVar1->sym == sym) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}

