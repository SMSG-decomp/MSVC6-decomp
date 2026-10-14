c2_live_range * __fastcall colour_queue_unlink(c2_live_range *lr,c2_live_range *head)

{
  c2_live_range *pcVar1;
  c2_live_range *pcVar2;
  
  pcVar1 = lr->queue_prev;
  if (pcVar1 == (c2_live_range *)0x0) {
    if (head == lr) {
      pcVar1 = (lr->u14).queue_next;
      head = (c2_live_range *)0x0;
      if (pcVar1 != (c2_live_range *)0x0) {
        pcVar1->queue_prev = (c2_live_range *)0x0;
        return pcVar1;
      }
    }
  }
  else {
    pcVar2 = (lr->u14).queue_next;
    (pcVar1->u14).queue_next = pcVar2;
    if (pcVar2 != (c2_live_range *)0x0) {
      pcVar2->queue_prev = pcVar1;
    }
  }
  return head;
}

