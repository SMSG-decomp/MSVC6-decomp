void __fastcall switch_case_unlink(c2_switch_case *c)

{
  c2_switch_case *pcVar1;
  c2_switch_case *pcVar2;
  
  pcVar1 = (c->owner->u24).cases;
  if (pcVar1 != c) {
    for (pcVar2 = pcVar1->next; pcVar2 != c; pcVar2 = pcVar2->next) {
      pcVar1 = pcVar2;
    }
    pcVar1->next = c->next;
    node_free((c2_node *)c);
    return;
  }
  (c->owner->u24).call = (c2_tuple_u24_call)c->next;
  node_free((c2_node *)c);
  return;
}

