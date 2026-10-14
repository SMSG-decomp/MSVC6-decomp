c2_live_range * __fastcall defer_live_range(c2_live_range *range,c2_live_range *lr)

{
  uint8_t uVar1;
  byte bVar2;
  int32_t iVar3;
  c2_live_range *pcVar4;
  int iVar5;
  int iVar6;
  c2_live_range *pcVar7;
  c2_live_range *pcVar8;
  
  pcVar8 = range;
  uVar1 = lr->sym->cls;
  (lr->u14).queue_next = (c2_live_range *)0x0;
  lr->queue_prev = (c2_live_range *)0x0;
  if (uVar1 == '\r') {
    pcVar7 = (range->u14).queue_next;
    while (pcVar4 = pcVar7, pcVar4 != (c2_live_range *)0x0) {
      range = pcVar4;
      pcVar7 = (pcVar4->u14).queue_next;
    }
    iVar3 = range->priority;
    (range->u14).queue_next = lr;
    lr->queue_prev = range;
    lr->priority = iVar3;
    return pcVar8;
  }
  bVar2 = range->flags5;
  pcVar7 = range;
  while (((bVar2 & 0x40) == 0 && (pcVar4 = (pcVar7->u14).queue_next, pcVar4 != (c2_live_range *)0x0)
         )) {
    bVar2 = pcVar4->flags5;
    pcVar7 = pcVar4;
  }
  if ((pcVar7->flags5 & 0x40) == 0) {
    iVar3 = pcVar7->priority;
    (pcVar7->u14).queue_next = lr;
    lr->queue_prev = pcVar7;
    lr->priority = iVar3;
    return pcVar8;
  }
  iVar5 = lr->weight;
  iVar6 = pcVar7->weight;
  if (((iVar5 <= iVar6) || (pcVar7->sym->cls == '\r')) && (pcVar7 == range)) {
    (lr->u14).queue_next = range;
    range->queue_prev = lr;
    lr->priority = range->priority;
    return lr;
  }
  while (((iVar6 < iVar5 && (pcVar7->sym->cls != '\r')) &&
         (pcVar4 = (pcVar7->u14).queue_next, pcVar4 != (c2_live_range *)0x0))) {
    iVar6 = pcVar4->weight;
    pcVar7 = pcVar4;
  }
  if ((pcVar7->weight < iVar5) && (pcVar7->sym->cls != '\r')) {
    iVar3 = pcVar7->priority;
    (pcVar7->u14).queue_next = lr;
    lr->queue_prev = pcVar7;
    lr->priority = iVar3;
    return pcVar8;
  }
  pcVar4 = pcVar7->queue_prev;
  iVar3 = pcVar7->priority;
  (lr->u14).queue_next = pcVar7;
  lr->queue_prev = pcVar4;
  (pcVar4->u14).queue_next = lr;
  pcVar7->queue_prev = lr;
  lr->priority = iVar3;
  return pcVar8;
}

