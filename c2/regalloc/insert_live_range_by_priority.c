c2_live_range * __fastcall insert_live_range_by_priority(c2_live_range *lr,c2_live_range *head)

{
  int iVar1;
  int iVar2;
  c2_live_range *pcVar3;
  c2_live_range *pcVar4;
  
  lr->flags5 = lr->flags5 & 0xfe;
  (lr->u14).queue_next = (c2_live_range *)0x0;
  if (head != (c2_live_range *)0x0) {
    iVar1 = lr->priority;
    iVar2 = head->priority;
    if ((iVar1 == iVar2 || iVar1 < iVar2) &&
       ((pcVar3 = head, iVar1 != iVar2 || (lr->tie < head->tie)))) {
      do {
        pcVar4 = pcVar3;
        if ((pcVar4->priority <= iVar1) && ((iVar1 != pcVar4->priority || (pcVar4->tie <= lr->tie)))
           ) break;
        pcVar3 = (pcVar4->u14).queue_next;
      } while ((pcVar4->u14).queue_next != (c2_live_range *)0x0);
      iVar2 = pcVar4->priority;
      if ((iVar2 == iVar1 || iVar2 < iVar1) && ((iVar2 != iVar1 || (pcVar4->tie <= lr->tie)))) {
        pcVar3 = pcVar4->queue_prev;
        (lr->u14).queue_next = pcVar4;
        lr->queue_prev = pcVar3;
        pcVar4->queue_prev = lr;
        (pcVar3->u14).queue_next = lr;
        return head;
      }
      (pcVar4->u14).queue_next = lr;
      lr->queue_prev = pcVar4;
      return head;
    }
    (lr->u14).queue_next = head;
    head->queue_prev = lr;
  }
  return lr;
}

