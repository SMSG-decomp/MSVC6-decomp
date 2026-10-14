void __fastcall switch_retarget(c2_tuple *referrer,c2_node *label,int retarget_cases)

{
  c2_tuple *label_00;
  c2_tuple *referrer_00;
  c2_tuple **label_slot;
  
  label_slot = (c2_tuple **)&referrer->u20;
  if (referrer->kind != '\x13') {
    label_slot = (c2_tuple **)&referrer->u14;
  }
  label_00 = *label_slot;
  label_remove_ref(label_00,(c2_node *)referrer);
  *label_slot = (c2_tuple *)label;
  label_add_ref((c2_tuple *)label,(c2_node *)referrer);
  if (retarget_cases != 0) {
    if (referrer->kind == '\x13') {
      referrer_00 = (c2_tuple *)(referrer->u24).cases;
    }
    else {
      referrer_00 = referrer->next;
    }
    for (; referrer_00 != (c2_tuple *)0x0; referrer_00 = referrer_00->next) {
      if ((referrer_00->u14).arg == label_00) {
        label_remove_ref(label_00,(c2_node *)referrer_00);
        (referrer_00->u14).scope_locals = (c2_list_cell *)label;
        label_add_ref((c2_tuple *)label,(c2_node *)referrer_00);
      }
    }
  }
  return;
}

