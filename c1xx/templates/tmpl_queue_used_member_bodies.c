char __cdecl tmpl_queue_used_member_bodies(void)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  c1_class_instance_cell *pcVar6;
  
  if ((g_template_work_queue == (c1_tmpl_work_queue *)0x0) || (g_template_work_queue->armed == '\0')
     ) {
    return '\0';
  }
  if (g_class_template_instances != (c1_class_instance_cell **)0x0) {
    pcVar6 = *g_class_template_instances;
    bVar4 = false;
    if (pcVar6 != (c1_class_instance_cell *)0x0) {
      do {
        piVar5 = pcVar6->bodies;
        if (((((pcVar6->instance->detail).cls)->flags3e & 0x10) == 0) && (g_opt_BforceInst == '\0'))
        {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        bVar3 = false;
        if (piVar5 != (int *)0x0) {
          do {
            iVar1 = *piVar5;
            if (((*(byte *)(iVar1 + 2) & 4) == 0) &&
               ((((*(byte *)(iVar1 + 0x18) & 3) != 0 || ((*(byte *)(iVar1 + 0x21) & 2) != 0)) ||
                (bVar2)))) {
              token_source_push(g_token_stream_queues,(c1xx_token_stream *)piVar5[1],0,1,(void *)0x0
                                ,&g_token_position);
              bVar3 = true;
            }
            piVar5 = (int *)piVar5[2];
          } while (piVar5 != (int *)0x0);
          if (bVar3) {
            bVar4 = true;
          }
        }
        pcVar6 = pcVar6->next;
      } while (pcVar6 != (c1_class_instance_cell *)0x0);
      if (bVar4) {
        return '\x01';
      }
    }
  }
  tmpl_work_queue_run(&g_template_work_queue->first);
  g_template_work_queue = (c1_tmpl_work_queue *)0x0;
  return '\x01';
}

