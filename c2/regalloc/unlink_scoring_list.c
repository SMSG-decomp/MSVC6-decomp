c2_live_range * __fastcall unlink_scoring_list(c2_live_range *head,c2_live_range *lr)

{
  c2_live_range *pcVar1;
  c2_live_range *pcVar2;
  c2_live_range *pcVar3;
  
  if (head != lr) {
    pcVar3 = (head->u14).queue_next;
    pcVar2 = head;
    while (pcVar1 = pcVar3, pcVar1 != lr) {
      pcVar2 = pcVar1;
      pcVar3 = (pcVar1->u14).queue_next;
    }
    pcVar2->u14 = lr->u14;
    return head;
  }
  return (head->u14).queue_next;
}

