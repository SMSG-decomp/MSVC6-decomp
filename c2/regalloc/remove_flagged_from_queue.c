c2_live_range * __fastcall remove_flagged_from_queue(c2_live_range *head)

{
  c2_live_range *pcVar1;
  c2_live_range *pcVar2;
  
  pcVar2 = head;
  while (pcVar1 = head, pcVar1 != (c2_live_range *)0x0) {
    head = (pcVar1->u14).queue_next;
    if ((pcVar1->flags5 & 2) != 0) {
      if (pcVar2 == pcVar1) {
        pcVar2 = head;
        if (head != (c2_live_range *)0x0) {
          head->queue_prev = (c2_live_range *)0x0;
        }
      }
      else {
        pcVar1 = pcVar1->queue_prev;
        (pcVar1->u14).queue_next = head;
        if (head != (c2_live_range *)0x0) {
          head->queue_prev = pcVar1;
        }
      }
    }
  }
  return pcVar2;
}

